#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include "helper.h"
#include "player.h"

using namespace std;
int main()
{
    int mapSize;
    initMapSize(mapSize);
    Player p{};

    // Create a 2D map using std::vector
    vector<vector<char>> map(mapSize, vector<char>(mapSize));
    initMap(map);
    bool gameOn = true;
    cout << "move over the map using wasd \navoid monsters (@) and move arong walls (#) to get your prize ($)"<<endl<<endl<<endl;
    displayMap(map);
    while (gameOn)
    {
        gameOn = takeTurn(p, map);
        if (gameOn)
            displayMap(map);
        else
        {
            cout << "GAME OVER!" << endl;
            break;
        }
        if (p.getxPos() == map.size() - 1 && p.getyPos() == map.size() - 1)
        {
            cout << "GAME WON!" << endl;
            gameOn = false;
        }
    }

    return 0;
}