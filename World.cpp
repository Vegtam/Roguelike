#include "World.hpp"
#include "Biome.hpp"
#include "Tile.hpp"
#include <vector>
#include <fstream>
#include <iostream>



World::World(int width, int height) : 
        worldMap(width, std::vector<Biome>(height)), 
        fillerMap(width, std::vector<float>(height)),
        elevationMap(width, std::vector<float>(height)),
        temperatureMap(width, std::vector<int>(height)),
        rainfallMap(width, std::vector<float>(height)),
        drainageMap(width, std::vector<bool>(height, false)),
        riverMap(width, std::vector<std::string>(height)),
        xSize(width), ySize(height){
    
}

World::~World() {
}

float World::random(float max){
	int r;
    float s;
    
	r = rand();
    s = (float)(r & 0x7fff)/(float)0x7fff;

    return (s * max);
}

World::color World::lerp(color c1, color c2, float value){
	color tcolor(0,0,0);
	
	for (int g=0;g<3;g++){
		if (c1.v[g]>c2.v[g])
			tcolor.v[g]=c2.v[g]+(unsigned char)(float(c1.v[g]-c2.v[g])*value);

		else
			tcolor.v[g]=c1.v[g]+(unsigned char)(float(c2.v[g]-c1.v[g])*value);
	}
	
	return (tcolor);
}

void World::buildMaps()
{
    
    
    std::cout << "Generated Filler Map" << std::endl;
    fillMap();    
    fillerMap.swap(elevationMap);
    std::cout << "Generated Elevation Map" << std::endl;
    fillMap();
    fillerMap.swap(rainfallMap);
    std::cout << "Generated Rainfall Map" << std::endl;
    generateBaseTemperature();
    std::cout << "Generated Base Temperatures" << std::endl;
    generateRiverSource();
    std::cout << "Generated Erosion and Rivers" << std::endl;
    

        
}

void World::clearMaps()
{    
    elevationMap.clear();
    rainfallMap.clear();
    temperatureMap.clear();
    drainageMap.clear();
    riverMap.clear();
    fillerMap.clear();
}

bool World::checkMaps()
{
    int mountainsHigh = 30;
    int mountainsLow = 20;
    
    int oceansHigh = 40;
    int oceansLow = 20;
    
    int aridityHigh = 10;
    int aridityLow = 1;
    
    int humidityHigh = 10;
    int humidityLow = 1;
    
    float mountain = 4.0f;
    float ocean = 0.0f;
    float arid = -0.5f;
    float humid = 4.0f;
    
    float totalSize = worldMap.size() * worldMap[0].size();
    float mountainCount = 0.0f;
    float oceanCount = 0.0f;
    float aridCount = 0.0f;
    float humidCount = 0.0f;
    
    
    
    for(int x = 0; x < worldMap.size(); ++x)
    {
        for(int y = 0; y < worldMap.size(); ++y)
        {
            if(elevationMap[x][y] >= mountain)
            {
                ++mountainCount;
            }
            else if(elevationMap[x][y] <= ocean)
            {
                ++oceanCount;
            }
            if(rainfallMap[x][y] >= humid)
            {
                ++humidCount;
            }
            else if(rainfallMap[x][y] <= arid)
            {
                ++aridCount;
            }
            
          
        }
    }
    
    int mountainPercentage = round(mountainCount/totalSize * 100);
    int oceanPercentage = round(oceanCount/totalSize * 100);
    int humidity = round(humidCount/totalSize * 100);
    int aridity = round(aridCount/totalSize * 100);
    
    if(mountainPercentage >= mountainsHigh or mountainPercentage <= mountainsLow)
    {
        return false;
    }
    if(oceanPercentage >= oceansHigh or oceanPercentage <= oceansLow)
    {
        return false;
    }
    if(humidity >= humidityHigh or humidity <= humidityLow)
    {
        return false;
    }
    if(aridity >= aridityHigh or aridity <= aridityLow)
    {
        return false;
    }
    
                
    
    std::cout << "Your map contains " << totalSize << " biomes." << std::endl;
    std::cout << mountainPercentage << "% of which are mountains." << std::endl;
    std::cout << oceanPercentage << "% of which are ocean." << std::endl;
    std::cout << "It has " << humidity << "% humidity." << std::endl;
    std::cout << "It has " << aridity << "% aridity." << std::endl;
    
    return true;
            
}

void World::fillMap(){
    
    
//set up some variable
    
	unsigned sgrid=((xSize<ySize) ? xSize : ySize)-1;//whichever is smaller (minus 1)
	
	int	i,j,k,//iterators
		x,y,//location variables
		offset=sgrid;//offset is the width of the square or diamond we are working with
		
	
	float range=10.0f,//range for random numbers
		  rangeModifier=0.65f,//the range is multiplied by this number each pass, making the map smoother
		  total,//variable for storing a mean value
		  temp;//stores the new value for a slot so more calculations can be done

	min=10.0f;
	max=0.0f;//for averaging

//get started
	//2.1 while the size of the squares and diamonds is larger than 1...
	while (offset>1){
		//reset variables
		y=0;
		
		//2.1.1 Diamond (create diamonds from squares)
		while (y<(ySize-1)){
			x=0;
			while (x<(xSize-1)){
				//set the proper map location to the proper value: the mean of it's 4 corners+a random value (minus half the range, so it generates a random number that can be negative
				temp=(fillerMap[x][y]+fillerMap[x+offset][y]+fillerMap[x][y+offset]+fillerMap[x+offset][y+offset])/4 + random(range)-(range/2);
				
                                if (temp<min)
					min=temp;
				if (temp>max)
					max=temp;
				
				fillerMap[x+(offset/2)][y+(offset/2)]=temp;
				
				//advance x
				x+=offset;
			}//end of diamond x while loop
			
			//advance y
			y+=offset;
		}//end of diamond y<gridsize loop
		
		//2.1.2 Square (create squares from diamonds) This is the tough part
		y=0;
		while (y<ySize){
                
			//set x to the correct offset
			x=(y+(offset/2))%offset;
			
			while (x<xSize){
				total=0;
				
				//wrapping exceptions
				if (x==0)//left edge
                                {
					total+=fillerMap[(ySize-1)-(offset/2)][y];
                                }
				else
                                {
					total+=fillerMap[x-(offset/2)][y];
                                }
				if (x==(xSize-1))//right edge
                                {
					total+=fillerMap[(offset/2)][y];
                                }
				else
                                {
					total+=fillerMap[x+(offset/2)][y];
                                }
				if (y==0)//top edge
                                {
					total+=fillerMap[x][(ySize-1)-(offset/2)];
                                }
				else
                                {
					total+=fillerMap[x][y-(offset/2)];
                                }
				if (y==(ySize-1))//bottom edge
                                {
					total+=fillerMap[x][(offset/2)];
                                }
				else
                                {
					total+=fillerMap[x][y+(offset/2)];
                                }
				
				total/=4;
				
				temp=total+random(range)-(range/2);
				if (temp<min)
					min=temp;
				if (temp>max)
					max=temp;
				fillerMap[x][y]=temp;
				
				//advance x
				x+=offset;
			}//end of square x<=gridsize loop
			
			//advance y (only half as much as x)
			y+=offset/2;
		}//end of square y<=gridsize loop
		
		//2.1.3 End of pass adjustments
		range*=rangeModifier;
		offset/=2;//shrink the square/diamond width
	}
    
}

void World::printMap(int mapType) {
    
    
    //set up some variables
        
	float diff = max-min,
		  flood=0.5f,//flood level
		  mount=0.85f;//mountain level
	
	flood*=diff;
	mount*=diff;
	
	int i,j,k;
	
	char c;
        
	//these can be changed for interesting results
         //elevation -Vegtam
        char oname[16]="elevation.bmp";
        
            
        color landlow(0,64,0),
              landhigh(116,182,133),
              waterlow(55,0,0),
              waterhigh(106,53,0),
              mountlow(147,157,167),
              mounthigh(226,223,216);

//3.0 output to file
	//3.1 Begin the file
	//3.1.1 open output file
	std::ofstream out;
	out.open(oname, std::ofstream::binary);
	if (!(out.is_open())){
		std::cout << "Target file opening error" << std::endl;
		exit(0);
	}
	
	//3.1.2 copy the header
		//3.1.2.1 magic number
		out.put(char(66));
		out.put(char(77));
		
		//3.1.2.2 file size/unused space
		for (i=0;i<8;i++)
			out.put(char(0));
		
		//3.1.2.3 data offset
		out.put(char(54));
		
		//3.1.2.4 unused space
		for (i=0;i<3;i++)
			out.put(char(0));
		
		//3.1.2.5 header size
		out.put(char(40));
		
		//3.1.2.6 unused space
		for (i=0;i<3;i++)
			out.put(char(0));
		
		//3.1.2.7 file width (trickier)
		out.put(char(xSize%256));
		out.put(char((xSize>>8)%256));
		out.put(char((xSize>>16)%256));
		out.put(char((xSize>>24)%256));
		
		//3.1.2.8 file height (trickier)
		out.put(char(ySize%256));
		out.put(char((ySize>>8)%256));
		out.put(char((ySize>>16)%256));
		out.put(char((ySize>>24)%256));
		
		//3.1.2.9 color planes
		out.put(char(1));
		out.put(char(0));
		
		//3.1.2.10 bit depth
		out.put(char(24));
		
		//3.1.2.11 the rest
		for (i=0;i<25;i++)
			out.put(char(0));
	
	//3.2 put in the elements of the array
	color newcolor(0,0,0);
	for (i=(ySize-1);i>=0;i--){//bitmaps start with the bottom row, and work their way up...
		for (j=0;j<xSize;j++){//...but still go left to right
			fillerMap[j][i]-=min;
			//if this point is below the floodline...
			if (fillerMap[j][i]<flood){
				newcolor=lerp(waterlow,waterhigh,fillerMap[j][i]/flood);
                                std::cout << "j = " << j << std::endl;
                                std::cout << "i = " << i << std::endl;
                                
                                std::cout << "value = " << fillerMap[j][i] << " is water." << std::endl;
                        }
			
			//if this is above the mountain line...
			else if (fillerMap[j][i]>mount){
				newcolor=lerp(mountlow,mounthigh,(fillerMap[j][i]-mount)/(diff-mount));
                                std::cout << "j = " << j << std::endl;
                                std::cout << "i = " << i << std::endl;
                                std::cout << "value = " << fillerMap[j][i] << " is mountain." << std::endl;
			}
			//if this is regular land
			else {
				newcolor=lerp(landlow,landhigh,(fillerMap[j][i]-flood)/(mount-flood));
                                std::cout << "j = " << j << std::endl;
                                std::cout << "i = " << i << std::endl;
                                std::cout << "value = " << fillerMap[j][i] << " is land." << std::endl;
                        }
			
			out.put(char(newcolor.v[0]));//blue
			out.put(char(newcolor.v[1]));//green
			out.put(char(newcolor.v[2]));//red
		}
		//round off the row
		for (k=0;k<(ySize%4);k++)
			out.put(char(0));
	}
	
	//3.3 end the file
	out.close();

}

Tile World::getTile(int xPos, int yPos)
{
    Tile tileDisplay = worldMap[xPos][yPos].getTile();
    
    return tileDisplay;
    
}


void World::buildBiomes()
{
    
    buildMaps();
    
    if(checkMaps())
    {
        for(int x = 0; x < worldMap.size(); x++)
        {
            for(int y = 0; y < worldMap[x].size(); y++)
            {

                worldMap[x][y].setElevation(elevationMap[x][y]);

                worldMap[x][y].setRainfall(rainfallMap[x][y]);

                worldMap[x][y].setTemperature(temperatureMap[x][y]);
                worldMap[x][y].setDrainage(drainageMap[x][y]);
                worldMap[x][y].setBiomeType();

            }

        }
    }
    
    else
    {
        std::cout << "World Requirements Failed, Rebuilding World" << std::endl;
        buildBiomes();
    }
    clearMaps();
     
}

void World::generateBaseTemperature()
{
    int northPole = 0;
    int equator = temperatureMap.size()/2;
    int southPole = temperatureMap.size();
    
    int northPoleTemp = 0;
    int equatorTemp = 90;
    int southPoleTemp = -20; 
    //but don't want to over-complicate, and pole seasons are switched so it's warmer in January...
    
    int temp = northPoleTemp;
    
    int diff = equatorTemp/equator;
    for(int y = northPole; y < southPole; ++y)
    {
        
        for(int x = 0; x < temperatureMap.size(); ++x)
        {
            temperatureMap[x][y] = temp;
        }
        
        if(y <= equator)
        {
            temp += diff;
        }

        else if(y > equator)
        {
            if(temp > southPoleTemp)
            {
                temp -= (diff * 1.25);
            }
            else
            {
                temp = southPoleTemp;
            }
            
        }
        
        
    }

}


void World::generateRiverSource()
{
    int north;
    int west;
    int south;
    int east;
    float mountain = 4.0f;
    float ocean = 0.0f;
    float semiarid = 0.5f;
    float arid = -1.0f;
    int x = 1;
    int y = 1;
    float curElevation;
    
    for(x; x < elevationMap.size() -1; ++x)
    {
        for(y; y < elevationMap[0].size() -1; ++y)
        {   
            
            if(elevationMap[x][y] >= mountain and rainfallMap[x][y] >= semiarid)
            {
                generateRiver(x, y);
            }
        }
    }
}

void World::generateRiver(int x, int y)
{
    std::cout << "Possible source at : " << x << " " << y << std::endl;
}
