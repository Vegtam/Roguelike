#include "World.hpp"
#include "Biome.hpp"
#include "Tile.hpp"
#include <vector>
#include <fstream>
#include <iostream>



World::World(int width, int height) : baseMap(width, std::vector<float>(height)),
worldMap(width, std::vector<Biome>(height)), xSize(width), ySize(height){
    
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

void World::fillMap(){
    
    std::cout << "filling map" << std::endl;
//set up some variable
    std::cout << "xSize = " << xSize << " ySize = " << ySize << std::endl;
	unsigned sgrid=((xSize<ySize) ? xSize : ySize)-1;//whichever is smaller (minus 1)
	
	int	i,j,k,//iterators
		x,y,//location variables
		offset=sgrid;//offset is the width of the square or diamond we are working with
		
	
	float range=10.0f,//range for random numbers
		  rangeModifier=0.65f,//the range is multipiled by this number each pass, making the map smoother
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
				temp=(baseMap[x][y]+baseMap[x+offset][y]+baseMap[x][y+offset]+baseMap[x+offset][y+offset])/4 + random(range)-(range/2);
				
                                if (temp<min)
					min=temp;
				if (temp>max)
					max=temp;
				
				baseMap[x+(offset/2)][y+(offset/2)]=temp;
				
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
					total+=baseMap[(ySize-1)-(offset/2)][y];
                                        std::cout << total << std::endl;
                                }
				else
                                {
					total+=baseMap[x-(offset/2)][y];
                                        std::cout << total << std::endl;
                                }
				if (x==(xSize-1))//right edge
                                {
					total+=baseMap[(offset/2)][y];
                                        std::cout << total << std::endl;
                                }
				else
                                {
					total+=baseMap[x+(offset/2)][y];
                                        std::cout << total << std::endl;
                                }
				if (y==0)//top edge
                                {
					total+=baseMap[x][(ySize-1)-(offset/2)];
                                        std::cout << total << std::endl;
                                }
				else
                                {
					total+=baseMap[x][y-(offset/2)];
                                        std::cout << total << std::endl;
                                }
				if (y==(ySize-1))//bottom edge
                                {
					total+=baseMap[x][(offset/2)];
                                        std::cout << total << std::endl;
                                }
				else
                                {
					total+=baseMap[x][y+(offset/2)];
                                        std::cout << total << std::endl;
                                }
				
				total/=4;
				
				temp=total+random(range)-(range/2);
				if (temp<min)
					min=temp;
				if (temp>max)
					max=temp;
				baseMap[x][y]=temp;
				
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
			baseMap[j][i]-=min;
			//if this point is below the floodline...
			if (baseMap[j][i]<flood){
				newcolor=lerp(waterlow,waterhigh,baseMap[j][i]/flood);
                                std::cout << "j = " << j << std::endl;
                                std::cout << "i = " << i << std::endl;
                                
                                std::cout << "value = " << baseMap[j][i] << " is water." << std::endl;
                        }
			
			//if this is above the mountain line...
			else if (baseMap[j][i]>mount){
				newcolor=lerp(mountlow,mounthigh,(baseMap[j][i]-mount)/(diff-mount));
                                std::cout << "j = " << j << std::endl;
                                std::cout << "i = " << i << std::endl;
                                std::cout << "value = " << baseMap[j][i] << " is mountain." << std::endl;
			}
			//if this is regular land
			else {
				newcolor=lerp(landlow,landhigh,(baseMap[j][i]-flood)/(mount-flood));
                                std::cout << "j = " << j << std::endl;
                                std::cout << "i = " << i << std::endl;
                                std::cout << "value = " << baseMap[j][i] << " is land." << std::endl;
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
    
    fillMap();
    //printMap(0);
    for(int x = 0; x < worldMap.size(); x++)
    {
        for(int y = 0; y < worldMap[x].size(); y++)
        {
            
            worldMap[x][y].setBiomeAttributes(baseMap[x][y]);
        }
            
    }
     
}

