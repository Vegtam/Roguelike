#include <iostream>
#include <cstdlib>
#include "Player.hpp"
using namespace std;

int main()
{
    
    Player player;
    player.Init();
    cout << player.GetAttribute(0) << endl;
    cout << player.GetChar() << endl;
    return 0;
}
