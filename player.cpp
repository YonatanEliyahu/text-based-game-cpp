#include "player.h"

bool Player::move(char direction, std::vector<std::vector<char>> &map)
{ // the following function will check if the player can move to the chosen direction
  // return false if player died, return true for valid movment
    int mapSize = map.size();
    int lastx=xPos;
    int lasty=yPos;
    char moveMark {};
    switch (direction)
    {
    case 'a':
        if (xPos > 0 && map[yPos][xPos - 1] != '#')
            xPos--;
            moveMark = '<';
        break;
    case 'd':
        if (xPos < mapSize - 1 && map[yPos][xPos + 1] != '#')
            xPos++;
            moveMark = '>';
        break;
    case 'w':
        if (yPos > 0 && map[yPos - 1][xPos] != '#')
            yPos--;
            moveMark = '^';
        break;
    case 's':
        if (yPos < mapSize - 1 && map[yPos + 1][xPos] != '#')
            yPos++;
            moveMark = 'v';
        break;
    }
    if (map[yPos][xPos] == '@')
        hp--;
    map[lasty][lastx]=moveMark;
    map[yPos][xPos] = 'i';
    if (hp == 0)
        return false;
    else
        return true;
}