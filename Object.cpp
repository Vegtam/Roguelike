#include "Object.hpp"
//todo Add mapFeature class as a child
Object::Object()
{

}

Object::~Object()
{

}

void Object::init(int x, int y, int backgroundColor, int foregroundColor, char character)
{
    this->worldX=worldX;
    this->worldY=worldY;
    this->backgroundColor=backgroundColor;
    this->foregroundColor = foregroundColor;
    this->character=character;
}

void Object::setWorldPosition(int worldX, int worldY)
{
    this->worldX=worldX;
    this->worldY=worldY;
}

void Object::setRegionPosition(int regionX, int regionY)
{
    this->regionX = regionX;
    this->regionY = regionY;
}

void Object::setLocalPosition(int localX, int localY)
{
    this->localX = localX;
    this->localY = localY;
}
