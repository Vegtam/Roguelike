#ifndef MAPMODEL_HPP
#define MAPMODEL_HPP

class MapModel
{
public:
    MapModel();
    virtual ~MapModel();
    
private:
    int selectedSize; //Large = 128 x 128, Medium = 64 x 64, Small = 32 x 32
    int mapViewType; //World, Region, Interior
    
    
};

#endif // MAPMODEL