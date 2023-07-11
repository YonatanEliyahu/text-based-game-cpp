#pragma once
#include <vector>

class Player{
    private:
        int xPos;
        int yPos;
        int hp;
    public:
        Player():xPos{0},yPos{0},hp{3}{}
        bool move(char direction,std::vector<std::vector<char>> &map);
        int getHP(){return hp;}
        int getxPos(){return xPos;}
        int getyPos(){return yPos;}
        
};