#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "World.hpp"
#include "Biome.hpp"
#include "BiomeTile.hpp"
#include "Tile.hpp"
#include "Random.hpp"



World::World(uint32_t width, uint32_t height) : 
        xSize(width), ySize(height),
        worldMap(width, std::vector<Biome>(height)){
    
}

World::~World() {
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

bool World::checkMaps(std::vector<std::vector<float> >& elevationMap, 
                      std::vector<std::vector<float> >& rainfallMap)
{
    
    
    uint8_t mountainsHigh = 20;
    uint8_t mountainsLow = 10;
    
    uint8_t oceansHigh = 40;
    uint8_t oceansLow = 30;
    
    uint8_t aridityHigh = 10;
    uint8_t aridityLow = 1;
    
    uint8_t humidityHigh = 10;
    uint8_t humidityLow = 1;
    
    float mountain = 4.0f;
    float ocean = 0.0f;
    float arid = -0.5f;
    float humid = 4.0f;
    
    float totalSize = worldMap.size() * worldMap[0].size();
    float mountainCount = 0.0f;
    float oceanCount = 0.0f;
    float aridCount = 0.0f;
    float humidCount = 0.0f;
    
    
    for(uint32_t x = 0; x < worldMap.size(); ++x)
    {
        for(uint32_t y = 0; y < worldMap[0].size(); ++y)
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
    
    uint8_t mountainPercentage = round(mountainCount/totalSize * 100);
    uint8_t oceanPercentage = round(oceanCount/totalSize * 100);
    uint8_t humidity = round(humidCount/totalSize * 100);
    uint8_t aridity = round(aridCount/totalSize * 100);
    
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
    std::cout << "You destroyed " << worldsCount << 
            " worlds in pursuit of your perfect world.  \nYou are become death, destroyer of worlds" << std::endl;
    
    return true;
            
}

void World::fillMap(std::vector<std::vector<float> >& fillerMap){
/*
 * vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv fillMap and printMap vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Copyright (c) 2009, Travis Archer
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
in the documentation and/or other materials provided with the distribution.

Neither the name of Morningside College nor the names of its contributors may be used to endorse or promote products derived 
from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/***************************************************************
*Fractal Terrain Generator
*created by Travis Archer
*
*This program creates a Fractal Terrain, using the
*	Diamond-Square technique described by Gavin S. P. Miller.
*
*1.0 initalizes variables (there are many)
*2.0 the map is created, this is the interesting part
*3.0 the map is outputted to a bitmap file. It should be noted
*	that the map is only a series of numbers before this step.
*	This step finds the flood level, and creates colors
*	accordingly. This part may be as interesting as 2.0 to some
*4.0 a webpage is created, displaying the bitmap
****************************************************************/
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^fillMap and printMap^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^   
    
//set up some variable
    
	unsigned sgrid=((xSize<ySize) ? xSize : ySize)-1;//whichever is smaller (minus 1)
	
//	uint32_t i,j,k,//iterators
	uint32_t x,y,//location variables
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
				temp=(fillerMap[x][y]+fillerMap[x+offset][y]+fillerMap[x][y+offset]+fillerMap[x+offset][y+offset])/4 + Random::get()->randFloat(range)-(range/2);
				
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
				
				temp=total+Random::get()->randFloat(range)-(range/2);
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

void World::printMap(uint32_t mapType, std::vector<std::vector<float> >& fillerMap) {
    
    
    //set up some variables
        
	float diff = max-min,
		  flood=0.5f,//flood level
		  mount=0.85f;//mountain level
	
	flood*=diff;
	mount*=diff;
	
	int32_t i,j,k;
	
	
        
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

Tile World::getTile(uint32_t xPos, uint32_t yPos)
{
    Tile tileDisplay = worldMap[xPos][yPos].getBiomeData().getTile();
    
    return tileDisplay;
    
}


void World::buildBiomes()
{
    bool built = false;
    std::vector<std::vector<float> > elevationMap(xSize, std::vector<float>(ySize));
    std::vector<std::vector<float> > rainfallMap (xSize, std::vector<float>(ySize));
    std::vector<std::vector<int> > temperatureMap (xSize, std::vector<int>(ySize));
    std::vector<std::vector<bool> > drainageMap (xSize, std::vector<bool>(ySize, false));

    worldsCount = 0;
     
    do{
        //std::cout << "Generated Filler Map" << std::endl;
        fillMap(elevationMap);
        //std::cout << "Generated Elevation Map" << std::endl;
        fillMap(rainfallMap);
        //std::cout << "Generated Rainfall Map" << std::endl;
        
        ++worldsCount;
        built = checkMaps(elevationMap,rainfallMap);
        
    } while(!built);

    generateBaseTemperature(temperatureMap);
    //std::cout << "Generated Base Temperatures" << std::endl;

    generateRiverSource(elevationMap,rainfallMap,drainageMap);
    //std::cout << "Generated Erosion, Lakes,  and Rivers" << std::endl;
    for(uint32_t x = 0; x < worldMap.size(); x++)
    {
        for(uint32_t y = 0; y < worldMap[x].size(); y++)
        {
            BiomeTile& biome = worldMap[x][y].getBiomeData();
            biome.setElevation(elevationMap[x][y]);
            biome.setRainfall(rainfallMap[x][y]);
            biome.setTemperature(temperatureMap[x][y]);
            biome.setDrainage(drainageMap[x][y]);
            biome.setBiomeTileType();
            int biomeType = biome.getBiomeTileType();
            Biome& region = worldMap[x][y];
            region.fillRegions(biomeType);
             
        }
    }
    firstTime = true;
}

void World::generateBaseTemperature(std::vector<std::vector<int> >& temperatureMap)
{
    int8_t northPole = 0;
    int32_t equator = temperatureMap.size()/2;
    int32_t southPole = temperatureMap.size();
    
    int8_t northPoleTemp = 0;
    int8_t equatorTemp = 90;
    int8_t southPoleTemp = -20; 
    //but don't want to over-complicate, and pole seasons are switched so it's warmer in January...
    
    int8_t temp = northPoleTemp;
    
    int8_t diff = equatorTemp/equator;
    for(int32_t y = northPole; y < southPole; ++y)
    {
        
        for(int32_t x = northPole; x < southPole; ++x)
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

void World::generateRiverSource(std::vector<std::vector<float> >& elevationMap, 
                                std::vector<std::vector<float> >& rainfallMap,
                                std::vector<std::vector<bool> > drainageMap )
{
    
    float mountain = 4.0f;
    //float ocean = 0.0f;
    float semihumid = 2.0f;
    //float arid = -1.0f;
    
    for(uint32_t x = 0; x < elevationMap.size(); ++x)
    {
        for(uint32_t y = 0; y < elevationMap[0].size(); ++y)
        {   
            
            if(elevationMap[x][y] >= mountain and rainfallMap[x][y] >= semihumid)
            {
                //std::cout << "River source at X: " << x << " Y: "  << y << std::endl;
                generateRiverPath(x, y,elevationMap,drainageMap);
                
            }
        }
    }
}

void World::generateRiverPath(uint32_t x, 
                              uint32_t y,
                              std::vector<std::vector<float> >& elevationMap,
                              std::vector<std::vector<bool> >& drainageMap)
{
    
    if(x != prevX and y != prevY)
    {
        
        
        if(x > 1 and x < worldMap.size() - 1 and y > 1 and y < worldMap[0].size() - 1)
        {
            //std::cout << "Starting river flow at X: " << x << " Y: " << y << std::endl;
            uint32_t curX = x;
            uint32_t curY = y;

            fillRiver(curX, curY, elevationMap, drainageMap);
        }
        else
        {
            
        }
    }
}

void World::fillRiver(uint32_t x, 
                      uint32_t y,
                      std::vector<std::vector<float> >& elevationMap,
                      std::vector<std::vector<bool> >& drainageMap)
{
    uint32_t north = x - 1;
    uint32_t west = y - 1;
    uint32_t south = x + 1;
    uint32_t east = y + 1;
    uint32_t newX = 0;
    uint32_t newY = 0;
    
    
    float lowest = elevationMap[x][y];
    if(x > 1 and x < worldMap.size() - 1 and y > 1 and y < worldMap[0].size() - 1)
    {
        //std::cout << " Prev Tile = X: " << prevX << " Y: " << prevY << std::endl;
        //std::cout << "Calculating flow for X: " << x << " Y: " << y << std::endl;
        //North
        if(elevationMap[north][y] < lowest and elevationMap[north][y] > 0 )
        {
            lowest = elevationMap[north][y];     
            newX = north;
        }
        //NorthWest
        if(elevationMap[north][west] < lowest and elevationMap[north][west] > 0)
        {
            lowest = elevationMap[north][west];  
            newX = north;
            newY = west;
        }
        //West
        if(elevationMap[x][west] < lowest and elevationMap[x][west] > 0)
        {
            lowest = elevationMap[x][west];
            newY = west;        
        }
        //SouthWest
        if(elevationMap[south][west] < lowest and elevationMap[south][west] > 0)
        {
            lowest = elevationMap[south][west];
            newX = south;
            newY = west;
        }
        //South
        if(elevationMap[south][y] < lowest and elevationMap[south][y] > 0)
        {
            lowest = elevationMap[south][y];
            newX = south;
        }
        //SouthEast
        if(elevationMap[south][east] < lowest and elevationMap[south][east] > 0)
        {
            lowest = elevationMap[south][east];
            newX = south;
            newY = east;
        }
        //East
        if(elevationMap[x][east] < lowest and elevationMap[x][east] > 0)
        {
            lowest = elevationMap[x][east];
            newY = east;
        }
        //NorthEast
        if(elevationMap[north][east] < lowest and elevationMap[north][east] > 0)
        {
            lowest = elevationMap[north][east];
            newX = north;
            newY = east;
        }
        else
        {


        }
        
    }
    
    if(!drainageMap[newX][newY] and newX > 1 and newY > 1 and newX < worldMap.size() - 1 and newY < worldMap[0].size() - 1)
    {
        if(newX != prevX and newY != prevY)
        {
            prevX = newX;
            prevY = newY;

            drainageMap[newX][newY] = true;
            //std::cout << "Flow moving towards X: " << newX << " Y: " << newY << std::endl;
            fillRiver(newX, newY, elevationMap, drainageMap);



        }

        else
        {
            //std::cout << "Flow blocked by elevation! X: " << x << " Y: " << y << "     This is the lowest point at " << elevationMap[x][y] * 100 << "ft." << std::endl;
            generateErosion(x, y, elevationMap, drainageMap); 

        }
    }
    
    
}

void World::generateErosion(uint32_t x, 
                            uint32_t y,
                            std::vector<std::vector<float> >& elevationMap,
                            std::vector<std::vector<bool> >& drainageMap)
{
    uint32_t north = x - 1;
    uint32_t west = y - 1;
    uint32_t south = x + 1;
    uint32_t east = y + 1;
    uint32_t newX = x;
    uint32_t newY = y;
    
    float currentElevation = elevationMap[x][y];
    
    float lowest = 10.0f;
    
    //North
        if(elevationMap[north][y] < lowest and elevationMap[north][y] > 0)
        {
            lowest = elevationMap[north][y];     
            newX = north;
        }
        //NorthWest
        if(elevationMap[north][west] < lowest and elevationMap[north][west] > 0)
        {
            lowest = elevationMap[north][west];  
            newX = north;
            newY = west;
        }
        //West
        if(elevationMap[x][west] < lowest and elevationMap[x][west] > 0)
        {
            lowest = elevationMap[x][west];
            newY = west;        
        }
        //SouthWest
        if(elevationMap[south][west] < lowest and elevationMap[south][west] > 0)
        {
            lowest = elevationMap[south][west];
            newX = south;
            newY = west;
        }
        //South
        if(elevationMap[south][y] < lowest and elevationMap[south][y] > 0)
        {
            lowest = elevationMap[south][y];
            newX = south;
        }
        //SouthEast
        if(elevationMap[south][east] < lowest and elevationMap[south][east] > 0)
        {
            lowest = elevationMap[south][east];
            newX = south;
            newY = east;
        }
        //East
        if(elevationMap[x][east] < lowest and elevationMap[x][east] > 0)
        {
            lowest = elevationMap[x][east];
            newY = east;
        }
        //NorthEast
        if(elevationMap[north][east] < lowest and elevationMap[north][east] > 0)
        {
            lowest = elevationMap[north][east];
            newX = north;
            newY = east;
        }
        else
        {


        }

    if(lowest <= currentElevation + 0.5f and 
       !drainageMap[newX][newY] and 
       newX > uint8_t(0) and 
       newY > uint8_t(0) and 
       newX < worldMap.size() and 
       newY < worldMap[0].size())
    {
        
        if(x != newX and y != newY)
        {
            prevX = newX;
            prevY = newY;
            elevationMap[newX][newY] = lowest - .1f;
            //std::cout << "Generating Erosion at X: " << newX << " Y: " << newY << 
            //            "\nNew Elevation = " << lowest * 100 << "ft" << std::endl;
            worldMap[newX][newY].getBiomeData().setElevation(lowest - .1f);
            fillRiver(newX, newY, elevationMap, drainageMap);
        }
               
        
        
    
    }
    
    else if(lowest > currentElevation + 0.1f)
    {
        //std::cout << "Generating Lake at X: " << x << " Y: " << y << std::endl;
        worldMap[x][y].getBiomeData().setLake(true);
    }
    
    
}
