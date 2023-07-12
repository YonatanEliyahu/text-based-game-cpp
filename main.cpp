#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <chrono>
#include "helper.h"
#include "player.h"

using namespace std;
int main()
{
    int mapSize;
    initMapSize(mapSize);
    Player p{};
    int timeLimitSeconds = mapSize * 1.5; // Set the time limit in seconds

    // Create a 2D map using std::vector
    vector<vector<char>> map(mapSize, vector<char>(mapSize));
    initMap(map);
    bool gameOn = true;
    cout << "move over the map using wasd \navoid monsters (@) and move arong walls (#) to get your prize ($)" << endl
         << endl
         << endl;
    displayMap(map);
    // Start the timer
    chrono::steady_clock::time_point startTime = chrono::steady_clock::now();
    while (gameOn)
    {
        // Check the elapsed time
        std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = currentTime - startTime;
        if (elapsedSeconds.count() >= timeLimitSeconds)
        {
            std::cout << "Time's up!" << std::endl;
            break; // Exit the game loop
        }
        std::cout << "time left " << (int)elapsedSeconds.count() << '/' << timeLimitSeconds << endl;
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