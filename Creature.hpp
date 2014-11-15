#ifndef CREATURE_HPP
#define CREATURE_HPP
#include "Object.hpp"

#define STR 0                   //indices of attribute array
#define DEX 1
#define VIT 2
#define MAG 3

class Creature : public Object
{
private:
    int Health, Mana;
    int Attribute[4];

public:
    Creature();                 // Construct Creature Object
    ~Creature();                // Destruct Creature Object

int GetHealth();                // Returns Health
int GetMana();                  // Returns Mana
int GetAttribute(int which);    // Returns Attributes

void SetHealth(int Health);               // Sets Health Level
void SetMana(int Mana);                 // Sets Mana Level
void SetAttribute(int which,
                  int value);   // Sets 4 Attributes [ 0 STR,1 DEX,2 VIT,3 MAG ]

};



#endif // CREATURE_HPP
