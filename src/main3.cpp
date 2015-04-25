#include <cstdlib>
#include "World.hpp"




int main(int argc, char** argv) {

    World newWorld(32, 32);
    
    newWorld.buildBiomes();
    
    return 0;
}

