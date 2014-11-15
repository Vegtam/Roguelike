#ifndef OBJECT_HPP
#define OBJECT_HPP




class Object
{
private:
    int x, y, color;
    char character;

public:
    Object(); //Constructor of Object
    ~Object(); //Destructor of Object
    void Init(int x, int y, int color, char character); //Initializes object

    int GetX(); // Returns X position of object
    int GetY(); // Returns Y position of object
    int GetColor(); // Return color of object
    char GetChar(); // Return representation of object

    void SetPosition(int x, int y); // Set position of object
    void SetColor(int color); // Set color of object
    void SetChar(char character); // Set representation of object
};



#endif // OBJECT_HPP
