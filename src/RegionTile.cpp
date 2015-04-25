#include "RegionTile.hpp"
#include "World.hpp"
#include "Model.hpp"
#include <iostream>

void RegionTile::displayRegionTileType(int regionType)
{
    switch(regionType)
    {
            case 0: // ocean 
                buildOceanRegion();
                //displayID = 247; // ~ 
                
                // blue          
                //backgroundR = 1;
                //backgroundG = 100;
                //backgroundB = 255;
                
                // light blue
                //foregroundR = 175;
                //foregroundG = 230;
                //foregroundB = 245;
                
                break;
        
            case 1: // Tropical moist forests 
                
                       
                buildTropicalMoistForestRegion();
                
                break;
                
            case 2: //Tropical dry forests
                
                buildTropicalDryForestRegion();
                
                break;
                
            case 3: // Tropical coniferous forests
                
                buildTropicalConiferousForestRegion();
                
                break;
                
            case 4: // Temperate broadleaf and mixed forests
                
                buildTemperateBroadleafMixForestRegion();
                
                break;
                
            case 5: // Temperate coniferous forests
                
                buildTemperateConiferousForestRegion();
                
                break;
                
            case 6: //  Boreal forests/taiga 
                
                buildBorealForestRegion();
                
                break;
                
            case 7: // Tropical grasslands, savannas, and shrublands
                
                buildTropicalGrasslandRegion();
                
                break;
                
            case 8: // Temperate grasslands, savannas, and shrublands
                
                buildTemperateGrasslandRegion();
                
                break;
                
            case 9: // Flooded grasslands and savannas
                
                buildFloodedGrasslandRegion();
                
                break;
                
            case 10: // Montane grasslands and shrublands
                
                buildMontaneRegion();
                
                break;
                
            case 11: // Tundra (Arctic)
                
                buildTundraRegion();
                
                break;
                
            case 12: // Mediterranean forests
                
                buildMediterraneanRegion();
                
                break;
                
            case 13: // Desert
                
                buildDesertRegion();
                
                break;
                
            case 14: // Mangrove
                
                buildMangroveRegion();
                
                break;
                
            default: // Not Set!!!! For debugging purposes
                
                displayID = 33; // !
                
                // Red
                backgroundR = 250;
                backgroundG = 1;
                backgroundB = 1;
                
                // Orange
                foregroundR = 250;
                foregroundG = 125;
                foregroundB = 1;
                
                break;
    }
}

void RegionTile::buildOceanRegion() 
{
    int regionNum = rand() % 4;
    
    switch(regionNum)
    {
        case 0:
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
            
        case 1:
            displayID = 247; // ~ 
                
            // green-blue          
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 200;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
                
        case 2:
            displayID = 247; // ~ 
                
            // greenish blue          
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            break;
            
        case 3:
            displayID = 247; // ~ 
                
            // dark blue          
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            break;
            
        case 4:
            displayID = 247; // ~ 
                
            // blue-green          
            backgroundR = 1;
            backgroundG = 200;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            
    }
}

void RegionTile::buildTropicalMoistForestRegion()
{
    
    //1. Lowland equatorial evergreen rain forests, commonly known as tropical rainforests,
        //are forests which receive high rainfall (more than 2000 mm, or 80 inches, 
        //annually) throughout the year. These forests occur in a belt around the equator, 
        //with the largest areas in the Amazon basin of South America, the Congo basin of central Africa, Indonesia, and New Guinea.
    
    //2. Moist deciduous and semi-evergreen seasonal forests, 
        //receive high overall rainfall with a warm summer wet season and a cooler winter dry season. 
        //Some trees in these forests drop some or all of their leaves during the winter dry season. 
        //These forests are found in parts of South America, in Central America and around the Caribbean, 
        //in coastal West Africa, parts of the Indian subcontinent, and across much of Indochina.
    
    //3. Montane rain forests, are found in cooler-climate mountainous areas. 
        //Those with elevations high enough to regularly encounter low-level cloud cover are known as cloud forests.
    
    //4. Flooded forests, including freshwater swamp forests and peat swamp forests.

    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        case 0:
            displayID = 5; // deciduous tree
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 1:
            displayID = 5; // deciduous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 2:
            displayID = 177; // tiny checkerboard
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
                
            break;
                
        case 3:
            displayID = 177; // deciduous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 4:
            displayID = 177; // deciduous tree
                
            // dark green
            backgroundR = 150;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
                
        case 5:
            displayID = 177; // deciduous tree
                
                // dark green
                backgroundR = 1;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium brown
                foregroundR = 150;
                foregroundG = 100;
                foregroundB = 1;
                
                forest = true;
                
                break;
            
    }
}

void RegionTile::buildTropicalDryForestRegion() 
{
    //1. The tropical and subtropical dry broadleaf forest biome, also known as tropical dry forest, 
        //vine thicket, and vine scrub is located at tropical and subtropical latitudes. 
        //Though these forests occur in climates that are warm year-round, and may receive several hundred centimeters of rain per year, 
        //they have long dry seasons which last several months and vary with geographic location. 
        //These seasonal droughts have great impact on all living things in the forest.
    
    //2. Deciduous trees predominate in most of these forests, and during the drought a leafless period occurs,
        //which varies with species type. 
        //Because trees lose moisture through their leaves, 
        //the shedding of leaves allows trees such as teak and mountain ebony to conserve water during dry periods. 
        //The newly bare trees open up the canopy layer, enabling sunlight to reach ground level and facilitate the growth of thick underbrush.
        //Trees on moister sites and those with access to ground water tend to be evergreen.
        //Infertile sites also tend to support evergreen trees. Three tropical dry broadleaf forest ecoregions, 
        //the East Deccan dry evergreen forests, the Sri Lanka dry-zone dry evergreen forests, 
        //and the Southeastern Indochina dry evergreen forests, are characterized by evergreen trees.
    
    //3. This biome is alternately known as the tropical bane forest biome or the tropical and subtropical deciduous forest biome. 
        //Locally some of these forests are also called monsoon forests, and they tend to merge into savannas.
    
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        case 0:
            
            displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 1:
            displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 2:
            displayID = 177; // tiny checkerboard
            
            // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
            // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
        case 3:
            displayID = 44; //comma
            
            // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
            // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
        case 4:
            displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                     
    }
            
}

void RegionTile::buildTropicalConiferousForestRegion()
{
    
    //Tropical and Subtropical coniferous forests are located near semi-humid areas. 
        //They vary in temperature and have low levels of precipitation.
        //This biome is made up of many species of conifers as well as many exotic species of flowers and animals. 
            
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        case 0:
            displayID = 6; // coneiferous tree
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 1:
            displayID = 6; // coneiferous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 2:
            displayID = 177; // tiny checkerboard
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
                
            break;
                
        case 3:
            displayID = 6; // coneiferous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 4:
            displayID = 6; // coneiferous tree
                
            // dark green
            backgroundR = 150;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
                
        case 5:
            displayID = 6; // coneiferous tree
                
                // dark green
                backgroundR = 1;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium brown
                foregroundR = 150;
                foregroundG = 100;
                foregroundB = 1;
                
                forest = true;
                
                break;
            
    }
}

void RegionTile::buildTemperateBroadleafMixForestRegion()
{
    //Temperate broadleaf and mixed forests occur in areas with distinct warm and cool season, 
        //which give it a moderate annual average temperature—3 to 15.6 °C (37 to 60 °F). 
        //These forests occur in relatively warm and rainy climates, sometimes also with a distinct dry season. 
        //A dry season occurs in the winter in East Asia and in summer on the wet fringe of the Mediterranean climate zones. 
        //Other areas have a fairly even distribution of rainfall; 
        //annual rainfall is typically over 600 mm (24 in) and often over 1,500 mm (59 in). 
        //Temperatures are typically moderate except in parts of Asia such as Ussuriland 
        //where temperate forests can occur despite very harsh conditions with very cold winters.
    
    int regionNum = rand() % 6;
    
    switch(regionNum)
    {
        case 0: 
                displayID = 6; // coneiforous tree
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 1:
                
            displayID = 6; // coneiferous tree (yes I made that up)
                
                // medium? brown
                backgroundR = 175;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 2:
            
            displayID = 6; // coneiferous tree (yes I made that up)
                
                // medium? brown
                backgroundR = 150;
                backgroundG = 125;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 3:
            
            displayID = 5; // deciduous tree
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 4:
            
            displayID = 5; // deciduous tree
                
                // medium brown
                backgroundR = 175;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 5:
            displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
    }
}

void RegionTile::buildTemperateConiferousForestRegion()
{
    //Temperate coniferous forest is a terrestrial biome found in temperate regions of the world 
        //with warm summers and cool winters and adequate rainfall to sustain a forest. 
        //In most temperate coniferous forests, evergreen conifers predominate, 
        //while some are a mix of conifers and broadleaf evergreen trees and/or broadleaf deciduous trees.
        //Temperate evergreen forests are common in the coastal areas of regions that have mild winters and heavy rainfall, 
        //or inland in drier climates or mountain areas. Coniferous forests can be found in the United States, Canada,
        //Europe, and Asia. Many species of tree inhabit these forests including 
        //cedar, cypress, Douglas fir, fir, juniper, kauri, pine, podocarpus, spruce, redwood and yew. 
        //The understory also contains a wide variety of herbaceous and shrub species.
    
    int regionNum = rand() % 5;
    
    switch(regionNum)
            
    {
        case 0:
            
            displayID = 6; // coniferous tree

            // medium brown
            backgroundR = 150;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 1:
            
            displayID = 6; // coniferous tree
            
            //medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium brown
            foregroundR = 100;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 2:
            
            displayID = 177; //tiny checkerboard
            
            //medium brown
            backgroundR = 100;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
        case 3:
            
            displayID = 5; //deciduous tree
            
            //medium brown
            backgroundR = 100;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 4:
            
            displayID = 6; //coniferous tree
            
            //dark brown
            backgroundR = 150;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;
            
            break;
    }
}

void RegionTile::buildBorealForestRegion()
{
    //The taiga is the world's largest terrestrial biome. 
        //In North America it covers most of inland Canada and Alaska 
        //as well as parts of the extreme northern continental United States 
        //(northern Minnesota through the Upper Peninsula of Michigan to Upstate New York and northern New England), 
        //where it is known as the Northwoods.[2] In Eurasia, it covers most of Sweden, Finland, much of Norway,
        //some lowland/coastal areas of Iceland, much of Russia from Karelia in the west to the Pacific Ocean 
        //(including much of Siberia), and areas of northern Kazakhstan, 
        //northern Mongolia, and northern Japan (on the island of Hokkaidō). However, the main tree species, 
        //the length of the growing season and summer temperatures vary. 
        //For example, the taiga of North America mostly consists of spruces; 
        //Scandinavian and Finnish taiga consists of a mix of spruce, pines and birch; 
        //Russian taiga has spruces, pines and larches depending on the region, while the Eastern Siberian taiga is a vast larch forest.
                
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        
        case 0:
                
            displayID = 6; // coniferous tree 

            // light green
            backgroundR = 1;
            backgroundG = 200;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 1:
            
            displayID = 6; //coniferous tree
            
            // white
            backgroundR = 255;
            backgroundG = 245;
            backgroundB = 245;
                
            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 2:
            
            displayID = 177; // tiny checkerboard
                
                // white
                backgroundR = 255;
                backgroundG = 245;
                backgroundB = 245;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                break;
                
        case 3:
            
            displayID = 177; // tiny checkerboard
                                
                // light green
                backgroundR = 1;
                backgroundG = 200;
                backgroundB = 1;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                break;
                
        case 4:
            
            displayID = 6; //coniferous tree
            
            // light green
                backgroundR = 1;
                backgroundG = 200;
                backgroundB = 1;
                
            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
    }
                
}

void RegionTile::buildTropicalGrasslandRegion()
{
    
    //Grasslands are dominated by grass and other herbaceous plants. 
        //Savannas are grasslands with scattered trees. Shrublands are dominated by woody or herbaceous shrubs.
        //Rainfall in tropical and subtropical grasslands, savannas, and shrublands is between 500 and 1300 millimeters (20 to 50 inches) a year,
        //and can be highly seasonal, with the entire year's rainfall sometimes occurring within a couple of weeks.
    
    int regionNum = rand() % 5;
    
    switch(regionNum)
        
    {
            case 0:
            
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
                
        case 1:
            
            displayID = 177; // tiny checkerboard 
                
                // dark brown
                backgroundR = 100;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
        case 2:
            
            displayID = 177; // tiny checkerboard 
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 125;
                foregroundB = 1;
                
                break;
                
        case 3:
            
            displayID = 177; // tiny checkerboard 
                
                // dark brown
                backgroundR = 100;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 125;
                foregroundB = 1;
                
                break;
                
        case 4:
            
            displayID = 177; // tiny checkerboard 
                
                // dark brown
                backgroundR = 100;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
    }
}

void RegionTile::buildTemperateGrasslandRegion()
{
    
    //Temperate grasslands, savannas, and shrublands is a terrestrial biome whose predominant vegetation consists of grasses and/or shrubs. 
        //The climate is temperate and ranges from semi-arid to semi-humid. 
        //Temperature: warm to hot season (often with a cold to freezing season in winter)
        //Soil: fertile with rich nutrients and minerals
        //Plants: grass; trees or shrubs in savanna and shrubland
        //Animals: large, grazing mammals; birds; reptiles

    //Steppes/shortgrass prairies are short grasslands that occur in semi-arid climates.
        //Tallgrass prairies are tall grasslands in areas of higher rainfall. Heaths and pastures are, 
        //respectively, low shrublands and grasslands where forest growth is hindered by human activity but not climate.

    //Tall grasslands, including the tallgrass prairie of North America and the Humid Pampas of Argentina, 
        //have moderate rainfall and rich soils which make them ideally suited to extensive agriculture, 
        //and tall grassland ecoregions include some of the most productive grain-growing regions in the world.

    //Savannas are areas with both grass and trees, but the trees do not form a canopy as they would in a forest.
    
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        case 0:
            
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
                
        case 1:
            
            displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 125;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
        case 2:
            
            displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 175;
                foregroundB = 1;
                
                break;
                
        case 3:
            
            displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 125;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 175;
                foregroundB = 1;
                
                break;
                
        case 4:
            
            displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 175;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
    }
}

void RegionTile::buildFloodedGrasslandRegion()
{
    
    //Coniferous swamp are forested wetlands in which the dominant trees are lowland conifers such as northern white cedar
        //(Thuja occidentalis). The soil in these swamp areas is typically saturated for most of the growing season 
        //and is occasionally inundated by seasonal storms or winter snow melt.
    
    //Dambo Dambo is a word used for a class of complex shallow wetlands in central, 
        //southern and eastern Africa, particularly in Zambia and Zimbabwe. 
        //They are generally found in higher rainfall flat plateau areas, 
        //and have river-like branching forms which may be nowhere very large, 
        //but common enough to add up to a large area. For instance, 
        //dambos have been estimated to comprise 12.5% of the area of Zambia.[1] 
        //Similar African words include mbuga (commonly used in East Africa),
        //matoro (Mashonaland), vlei (South Africa), fadama (Nigeria), and bolis (Sierra Leone); 
        //the French bas-fond and German Spültal have also been suggested as referring to similar grassy wetlands.
    
    //Fen A fen is one of the four main types of wetland, the others being grassy marshes, forested swamps, and peaty bogs.
        //Along with bogs, fens are a kind of mire. Fens are usually fed by mineral-rich surface water or groundwater.[1] 
        //They are characterised by their water chemistry, which is pH neutral or alkaline, 
        //with relatively high dissolved mineral levels but few other plant nutrients. 
        //They are usually dominated by grasses and sedges, and typically have brown mosses in general 
        //including Scorpidium or Drepanocladus.[2] Fens frequently have a high diversity of other plant species 
        //including carnivorous plants such as Pinguicula.[3][4] 
        //They may also occur along large lakes and rivers where seasonal changes in water level maintain wet soils with few woody plants.[5] 
        //The distribution of individual species of fen plants is often closely connected to water regimes and nutrient concentrations
    
    //Flood-meadow
    //Freshwater swamp forest
    //Hydrogen sulfide
    //Mangroves
    //Marsh
    //Marsh gas
    //Muck (soil)
    //Peat
    //Peat swamp forest
    //Salt marsh
    //Shrub swamp
    //Water-meadow
    //Wet meadow

    int regionNum = rand() % 3;
    
    switch(regionNum)
    {
        
        case 0:
            
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
                
        case 1:
            
            displayID = 177; // thin diagonal lines
                
                // brownish grey 
                backgroundR = 130;
                backgroundG = 100;
                backgroundB = 75;
                
                // medium blue
                foregroundR = 125;
                foregroundG = 135;
                foregroundB = 75;
                
                break;
                
                case 2:
                    
                    displayID = 176; // thin diagonal lines
                
                // brownish grey 
                backgroundR = 130;
                backgroundG = 100;
                backgroundB = 75;
                
                // medium blue
                foregroundR = 125;
                foregroundG = 135;
                foregroundB = 100;
                
                break;
                    
                    
    }
}

void RegionTile::buildMontaneRegion() 
{
    
    int regionNum = rand() % 3;
    
    switch(regionNum)
    {
        case 0:
                
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
                
                case 1:
                    
                    displayID = 6; // coniferous tree
                
                // light green
                backgroundR = 115;
                backgroundG = 185;
                backgroundB = 1;
                
                // dark gray 
                foregroundR = 135;
                foregroundG = 130;
                foregroundB = 120;
                
                forest = true;
                
                break;
                
                case 2:
                    
                    displayID = 177; // tiny checkerboard
                
                // light green
                backgroundR = 115;
                backgroundG = 185;
                backgroundB = 1;
                
                // dark gray 
                foregroundR = 135;
                foregroundG = 130;
                foregroundB = 120;
                
                break;
                
    }
}

void RegionTile::buildTundraRegion()
{
    int regionNum = rand() % 3;
    switch(regionNum)
    {
        case 0:
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
                
        case 1:
            
            displayID = 177; // tiny checkerboard, prev 236 filled small circle
                
                // white
                backgroundR = 225;
                backgroundG = 245;
                backgroundB = 245;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                break;
                
        case 2:
            
            displayID = 236; // filled small circle
                
                // white
                backgroundR = 255;
                backgroundG = 245;
                backgroundB = 245;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 175;
                
                break;
    }          
}


void RegionTile::buildMediterraneanRegion() 
{
    
    int regionNum = rand() % 3;
    
    switch(regionNum)
    {
        case 0:
            
        displayID = 23; //coneiduous tree
                
                // medium green
                backgroundR = 1;
                backgroundG = 150;
                backgroundB = 1;
                
                // light green
                foregroundR = 1;
                foregroundG = 200;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 1:
            displayID = 177; //tiny checkerboard
                
                // medium green
                backgroundR = 1;
                backgroundG = 150;
                backgroundB = 1;
                
                // light green
                foregroundR = 1;
                foregroundG = 200;
                foregroundB = 1;
                
                break;
                
        case 2:
            displayID = 23; //coneiduous tree
                
                // medium green
                backgroundR = 1;
                backgroundG = 150;
                backgroundB = 1;
                
                // light green
                foregroundR = 1;
                foregroundG = 225;
                foregroundB = 1;
                
                forest = true;
                
                break;
            
    }
                
}

void RegionTile::buildDesertRegion()
{
    int regionNum = rand() % 3;
    
    switch(regionNum)
    {
        case 0:
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
                
        case 1:
            
            displayID = 143; // tilde
                
                // tan
                backgroundR = 250;
                backgroundG = 225;
                backgroundB = 160;
                
                // orange
                foregroundR = 255;
                foregroundG = 185;
                foregroundB = 1;
                
                break;
                
        case 2:
            
            displayID = 252; // short rounded arch
                
                // tan
                backgroundR = 250;
                backgroundG = 225;
                backgroundB = 160;
                
                // orange
                foregroundR = 255;
                foregroundG = 185;
                foregroundB = 1;
                
                break;
    }
}

void RegionTile::buildMangroveRegion()
{
    
    int regionNum = rand() % 3;
    
    switch(regionNum)
    {
        case 0:
            
        displayID = 244; // big tree
                
                // medium blue
                backgroundR = 1;
                backgroundG = 125;
                backgroundB = 255;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 1:
            
            displayID = 177; // checkerboard
                
                // medium blue
                backgroundR = 1;
                backgroundG = 125;
                backgroundB = 255;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
        case 2:
            
            displayID = 247; // double tilde
                
                // medium blue
                backgroundR = 1;
                backgroundG = 125;
                backgroundB = 255;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                lake = true;
                
                break;
                
                
    }
}

Tile RegionTile::getTile()
{
    return Tile(displayID, al_map_rgb(backgroundR,backgroundG,backgroundB), al_map_rgb(foregroundR,foregroundG,foregroundB));
}

void RegionTile::setRegionTileType(int biomeType)
{
    
    
    displayRegionTileType(biomeType);
}