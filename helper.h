#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include "player.h"
using namespace std;

void initMapSize(int &mapSize);
void initMap(vector<vector<char>> &map);
void displayMap(vector<vector<char>> &map);
bool takeTurn(Player &p,vector<vector<char>> &map);