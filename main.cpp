#include <cstdlib>
#include "World.hpp"




int main(int argc, char** argv) {

    World newWorld(32, 32);
    
    newWorld.buildBiomes();
    
    for(int i = 0; i < newWorld.baseMap.size(); i++)
    
    return 0;
}

