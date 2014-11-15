#include "Object.hpp"
//todo Add mapFeature class as a child
Object::Object()
{

}

Object::~Object()
{

}

void Object::Init(int x, int y, int color, char character)
{
    this->x=x;
    this->y=y;
    this->color=color;
    this->character=character;
}

int Object::GetX()
{
    return x;
}

int Object::GetY()
{
    return y;
}

int Object::GetColor()
{
    return color;
}

char Object::GetChar()
{
    return character;
}

void Object::SetPosition(int x, int y)
{
    this->x=x;
    this->y=y;
}

void Object::SetColor(int color)
{
    this->color=color;
}

void Object::SetChar(char character)
{
    this->character=character;
}
