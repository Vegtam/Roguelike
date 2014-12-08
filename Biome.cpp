#include "Biome.hpp"

Biome::Biome() {
}

Biome::Biome(const Biome& orig) {
}

Biome::~Biome() {
}

void Biome::setDisplayID(int biomeType)
{
    displayID = biomeType;
}

int Biome::getDisplayID()
{
    return displayID;
}