#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include "helper.h"

using namespace std;
int main()
{
    int mapSize;
    initMapSize(mapSize);

    // Create a 2D map using std::vector
    vector<vector<int>> map(mapSize, vector<int>(mapSize));
    initMap(map);

    return 0;
}