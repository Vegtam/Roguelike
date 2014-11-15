#include "Creature.hpp"

Creature::Creature()
{

}

Creature::~Creature()
{

}

int Creature::GetHealth()
{
    return Health;
}

int Creature::GetMana()
{
    return Mana;
}

int Creature::GetAttribute(int which)
{
    return Attribute[which];
}

void Creature::SetHealth(int Health)
{
    this->Health=Health;
}

void Creature::SetMana(int Mana)
{
    this->Mana=Mana;
}

void Creature::SetAttribute(int which, int value)
{
    this->Attribute[which]=value;
}
