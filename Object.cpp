#include "Object.hpp"
//todo Add mapFeature class as a child
Object::Object()
{

}

Object::~Object()
{

}

void Object::init(int x, int y, int backColor, int foreColor, char chr)
{
    worldX=x;
    worldY=y;
    backgroundColor=backColor;
    foregroundColor = foreColor;
    character=chr;
}

