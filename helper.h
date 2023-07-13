#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include "player.h"
using namespace std;

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

void initMapSize(int &mapSize);
void initMap(vector<vector<char>> &map);
void displayMap(const vector<vector<char>> &map);
bool takeTurn(Player &p, vector<vector<char>> &map);