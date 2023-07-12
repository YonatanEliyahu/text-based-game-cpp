#include "helper.h"

void initMapSize(int &mapSize)
{
    string temp;
    istringstream iss;
    do
    {
        cout << "enter map size (10 minimun): " << endl;
        getline(cin, temp);
        iss.str(temp);
        if (iss >> mapSize)
            ;
        else
            mapSize = 0;
    } while (mapSize < 10);
}

void initMap(vector<vector<char>> &map)
{
    int mapSize = map.size();
    // setting the map to an empty
    for (int i = 0; i < mapSize; i++)
        for (int j = 0; j < mapSize; j++)
            map[i][j] = ' ';

    map[0][0] = 'i'; // locate player

    random_device rd;  // Obtain a random seed from the hardware
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    uniform_int_distribution<> dis(0, mapSize - 1); // setting generator of random integers

    for (int i = 1; i < mapSize; i++)
    { // for every line - generate random location in the map for walls and monsters
        int wallPos = dis(gen);
        for (int j = -(mapSize/ 7); j <= (mapSize / 7); j++)
        {
            if (wallPos+j >=0 && wallPos+j <mapSize)
                map[i][wallPos+j] = '#';
        }
        do
        {
            int monsterPos = dis(gen);
            if (map[i][monsterPos] == ' ')
            {
                map[i][monsterPos] = '@';
                break;
            }
        } while (true);
    }
    map[mapSize - 1][mapSize - 1] = '$'; // locate prize
}
void displayMap(vector<vector<char>> &map)
{
    for (int i = 0; i < map.size(); i++)
    {
        cout << '|';
        for (int j = 0; j < map.size(); j++)
            cout << map[i][j] << ' ';
        cout << '|' << endl;
    }
}

bool takeTurn(Player &p, vector<vector<char>> &map)
{
    char dir;
    do
    {
        cout << "make a move using ASDW" << endl
             << "hp left: " << p.getHP() << endl;
        cin >> dir;
        cin.ignore(10000, '\n');
    } while (dir != 'a' && dir != 's' && dir != 'd' && dir != 'w');
    return p.move(dir, map);
}