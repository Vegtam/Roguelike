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

    inline void setWorldPosition(int x, int y){ worldX=x; worldY=y; }; // Set position of object in world map
    // Set position of object in region map (region map XSize = WorldMapWidth*BiomeWidth, YSize = WorldMapHeight*BiomeHeight)
    inline void setRegionPosition(int x, int y){regionX=x; regionY=y;}; 
    // Set position of object in local map (local map xSize = region map Xsize*RegionWidth, YSize = region map YSize * RegionWidth)
    inline void setLocalPosition(int x, int y){localX=x; localY=y;}; 
    inline void setBackgroundColor(int backgroundColor){this->backgroundColor = backgroundColor;}; // Set background color of object
    inline void setForegroundColor(int foregroundColor){this->foregroundColor = foregroundColor;}; // Set foreground color of object
    inline void setChar(char character){this->character = character;}; // Set representation of object
};



#endif // OBJECT_HPP
