#include "Biome.hpp"
#include <iostream>

/*
  
    -01 Tropical and subtropical moist broadleaf forests (tropical and subtropical, humid)
    -02 Tropical and subtropical dry broadleaf forests (tropical and subtropical, semihumid)
    -03 Tropical and subtropical coniferous forests (tropical and subtropical, semihumid)
    -04 Temperate broadleaf and mixed forests (temperate, humid)
    -05 Temperate coniferous forests (temperate, humid to semihumid)
    -06 Boreal forests/taiga (subarctic, humid)
    -07 Tropical and subtropical grasslands, savannas, and shrublands (tropical and subtropical, semiarid)
    -08 Temperate grasslands, savannas, and shrublands (temperate, semiarid)
    -09 Flooded grasslands and savannas (temperate to tropical, fresh or brackish water inundated)
    -10 Montane grasslands and shrublands (alpine or montane climate)
    -11 Tundra (Arctic)
    -12 Mediterranean forests, woodlands, and scrub or sclerophyll forests (temperate warm, semihumid to semiarid with winter rainfall)
    -13 Deserts and xeric shrublands (temperate to tropical, arid)
    -14 Mangrove (subtropical and tropical, salt water inundated)

 */

Biome::Biome() {
}

Biome::Biome(const Biome& orig) {
}

Biome::~Biome() {
}

void Biome::setBiomeType()
{
    float sealevel = 0.0f;// 0.0f sea level
    float flood = 0.5f; // .5f flood zone
    float mount = 4.0f;// 4 mountain level
    
    float humid = 4.0f; // 4 high rainfall
    float semihumid = 2.0f; // 2 med high rainfall
    float semiarid = 0.5f; // .5 med low rainfall
    float arid = -1.0f; // .0 low rainfall
    
    int tropical = 64; // 64 Hot Temperature
    int arctic = 15; // 15 Cold Temperature 
    
    
    
    
    if(elevation <= sealevel)
    {
        biomeType = 0; // Ocean
    }
    
    else if(elevation >= mount)
    {
        biomeType = 10; // Montane
    }
    
    else if(elevation > sealevel and elevation <= flood)
    {
        if(temperature >= tropical)
        {
            biomeType = 14; //Mangrove Forest
        }
        
        else if(temperature <= arctic)
        {
           if(rainfall >= humid)
            {
                biomeType = 6; //Boreal Forest
            }
            
            else
            {
                biomeType = 11; //Tundra
            }
            
        }
        
        else// if(temperature > arctic and temperature < tropical)
        {
            biomeType = 9; //Flooded Grasslands
        }   
        
    }   //end elevation in flood plain
    else if(elevation > flood and elevation < mount)
    {
        if(temperature <= arctic) //Boreal Forest or Tundra
        {
            if(rainfall >= semihumid)
            {
                biomeType = 6; //Boreal Forest
            }
            
            else// if(rainfall < humid)
            {
                biomeType = 11; //Tundra
            }
            
        }//end of arctic temperatures
        
        else if(temperature >= tropical)
        {
            if(rainfall <= arid)
            {
                biomeType = 13; //Desert
            }

            else if(rainfall < humid and rainfall >= semihumid)
            {
                biomeType = 2; //Tropical Dry Broadleaf Forest

            }
            
            else if(rainfall < semihumid and rainfall > semiarid)
            {
                biomeType = 3; //Tropical Coniferous Forest
            }

            else //if(rainfall <= semiarid and rainfall > arid)
            {
                biomeType = 7; //Tropical grasslands
            }
            
        }//end of tropical temperatures
            
        else if(temperature < tropical and temperature > arctic)
        {
            if(rainfall >= humid)
            {
                biomeType = 4; //Broadleaf Forest
            }
            
            
            else if(rainfall <= arid)
            {
                biomeType = 13; //Desert
            }
            
            else if(rainfall < semihumid and rainfall > semiarid)
            {
                biomeType = 5; //Coniferous Forest
            }
            
            else if(rainfall <= semiarid and rainfall > arid)
            {
                biomeType = 8; //Grassland
            }
            
            else
            {
                biomeType = 12; //Mediterranean Forest
            }
            
        } //end of temperate temperatures  
    
    }
    
    else
    {
        biomeType = 15; //Not Set!!!
    }
    
    
    
    std::cout << "Setting Elevation for Biome: " << elevation << std::endl;
    std::cout << "Setting Rainfall for Biome: " << rainfall << std::endl;
    std::cout << "Setting Temperature for Biome: " << temperature << std::endl;
    
    
    
    switch(biomeType)
    {
            case 0: // ocean 
                
                displayID = 247; // ~ 
                
                // blue          
                backgroundR = 1;
                backgroundG = 100;
                backgroundB = 255;
                
                // light blue
                foregroundR = 175;
                foregroundG = 230;
                foregroundB = 245;
                
                break;
        
            case 1: // Tropical moist forests 
                
                displayID = 5; // deciduous tree
                
                // dark green
                backgroundR = 1;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 2: //Tropical dry forests
                
                displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 3: // Tropical coniferous forests
                
                displayID = 6; // coniferous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
            case 4: // Temperate broadleaf and mixed forests
                
                displayID = 23; // coneiduous tree (yes I made that up)
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 5: // Temperate coniferous forests
                
                displayID = 6; // coniferous tree
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 6: //  Boreal forests/taiga 
                
                displayID = 6; // coniferous tree 
                
                // light green
                backgroundR = 1;
                backgroundG = 200;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 7: // Tropical grasslands, savannas, and shrublands
                
                displayID = 177; // tiny checkerboard 
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
            case 8: // Temperate grasslands, savannas, and shrublands
                
                displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 9: // Flooded grasslands and savannas
                
                displayID = 176; // thin diagonal lines
                
                // brownish grey 
                backgroundR = 130;
                backgroundG = 100;
                backgroundB = 75;
                
                // medium blue
                foregroundR = 125;
                foregroundG = 135;
                foregroundB = 75;
                
                break;
                
            case 10: // Montane grasslands and shrublands
                
                displayID = 94; // pointed arch 
                
                // light green
                backgroundR = 115;
                backgroundG = 185;
                backgroundB = 1;
                
                // dark gray 
                foregroundR = 135;
                foregroundG = 130;
                foregroundB = 120;
                
                break;
                
            case 11: // Tundra (Arctic)
                
                displayID = 177; // tiny checkerboard, prev 236 filled small circle
                
                // white
                backgroundR = 255;
                backgroundG = 245;
                backgroundB = 245;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                break;
                
            case 12: // Mediterranean forests
                
                displayID = 23; //coneiduous tree
                
                // medium green
                backgroundR = 1;
                backgroundG = 150;
                backgroundB = 1;
                
                // light green
                foregroundR = 1;
                foregroundG = 200;
                foregroundB = 1;
                
                break;
                
            case 13: // Desert
                
                displayID = 15; // sun
                
                // tan
                backgroundR = 250;
                backgroundG = 225;
                backgroundB = 160;
                
                // orange
                foregroundR = 255;
                foregroundG = 185;
                foregroundB = 1;
                
                break;
                
            case 14: // Mangrove
                
                displayID = 244; // big tree
                
                // medium blue
                backgroundR = 1;
                backgroundG = 125;
                backgroundB = 255;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
            case 15: // Not Set!!!!
                
                displayID = 33; // !
                
                // Red
                backgroundR = 250;
                backgroundG = 1;
                backgroundB = 1;
                
                // Orange
                foregroundR = 250;
                foregroundG = 125;
                foregroundB = 1;
                
                
                
                
    }

 /*   
  * Elevation Debugging
  * 
    if(elevation > mount)
    {
 
        displayID = 94; // pointed arch 
                
                    // light green
                    backgroundR = 115;
                    backgroundG = 185;
                    backgroundB = 1;
                
                    // dark gray 
                    foregroundR = 135;
                    foregroundG = 130;
                    foregroundB = 120;
    }
    else if(elevation < flood)
    {
        displayID = 247; // ~ 
                
                    // blue          
                    backgroundR = 1;
                    backgroundG = 100;
                    backgroundB = 255;
                
                    // light blue
                    foregroundR = 175;
                    foregroundG = 230;
                    foregroundB = 245;
    }
    else
    {
        displayID = 0; // blank 
                
                // light green
                backgroundR = 115;
                backgroundG = 185;
                backgroundB = 1;
                
                // light green
                backgroundR = 115;
                backgroundG = 185;
                backgroundB = 1;
    }
  */
    /*
  //Temperature Debugging
    if(temperature > tropical)
    {
        //displayID = 0; // blank
            //red
        backgroundR = 250;
        backgroundG = 1;
        backgroundB = 1;
    }

    else if(temperature < arctic)
    {
        //displayID = 0; //blank
            //blue
        backgroundR = 1;
        backgroundG = 1;
        backgroundB = 250;
    }
    
    else
    {
        //displayID = 0; //blank
            //purple
        backgroundR = 125;
        backgroundG = 1;
        backgroundB = 125;
    }
    */
    
    
} 


Tile Biome::getTile()
{
    return Tile(displayID, al_map_rgb(backgroundR,backgroundG,backgroundB), al_map_rgb(foregroundR,foregroundG,foregroundB));
}

