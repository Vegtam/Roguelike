#include <iostream>
#include <cstdlib>
#include "Player.hpp"


int main()
{
    using namespace std;
    Player* player=new Player();
    player -> Init();
    cout << player->GetAttribute(0) << endl;
    cout << player->GetChar() << endl;
    system("PAUSE");
    delete player;
    return 0;
}
