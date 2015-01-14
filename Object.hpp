#ifndef OBJECT_HPP
#define OBJECT_HPP




class Object
{
private:
    int worldX, worldY, regionX, regionY, localX, localY, backgroundColor, foregroundColor;
    char character;

public:
    Object(); //Constructor of Object
    virtual ~Object(); //Destructor of Object
    void init(int worldX, int worldY, int foregroundColor, int backgroundColor, char character); //Initializes object

    inline int getWorldX(){return worldX;}; // Returns X position of object in world map
    inline int getWorldY(){return worldY;}; // Returns Y position of object in world map
    inline int getRegionX(){return regionX;}; // Returns X position of object in region map
    inline int getRegionY(){return regionY;}; // Returns Y position of object in region map
    inline int getLocalX(){return localX;}; // Returns X position of object in local map
    inline int getLocalY(){return localY;}; // Returns Y position of object in local map
    inline int getBackgroundColor(){return backgroundColor;}; // Return background color of object
    inline int getForegroundColor(){return foregroundColor;}; // Return foreground color of object
    inline char getChar(){return character;}; // Return representation of object

    void setWorldPosition(int worldX, int worldY); // Set position of object in world map
    void setRegionPosition(int regionX, int regionY); // Set position of object in region map
    void setLocalPosition(int localX, int localY); // Set position of object in local map
    inline void setBackgroundColor(int backgroundColor){this->backgroundColor = backgroundColor;}; // Set background color of object
    inline void setForegroundColor(int foregroundColor){this->foregroundColor = foregroundColor;}; // Set foreground color of object
    inline void setChar(char character){this->character = character;}; // Set representation of object
};



#endif // OBJECT_HPP
