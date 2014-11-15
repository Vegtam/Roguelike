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
    Creature::Init(32, 32, 2, '@');
    Creature::SetAttribute(STR, 10);
}