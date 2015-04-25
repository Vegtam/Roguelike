#include "Player.hpp"
//todo implement level experience/ skills that grow with use.
Player::Player()
{

}

Player::~Player()
{

}

void Player::init()
{
    Creature::init(16, 16, 155, 1, 2);
}