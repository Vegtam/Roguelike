#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Creature.hpp"

class Player : public Creature
{
public:
    Player();       // Construct Player
    virtual ~Player();      // Destruct Player
    void Init();    // Initialize Player
};

#endif // PLAYER_HPP
