#include "Player.hpp"
//todo implement level experience/ skills that grow with use.
Player::Player()
{

}

Player::~Player()
{

}

void Player::Init()
{
    Creature::Init(16, 16, 2, 2);
    Creature::SetAttribute(STR, 10);
}