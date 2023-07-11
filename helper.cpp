#include "helper.h"

void initMapSize(int &mapSize){
    string temp;
    istringstream iss;
    do
    {
        cout << "enter map size: " << endl; 
        getline(cin, temp);
        iss.str(temp);
        if(iss >> mapSize);
        else
            mapSize=0;
    } while (mapSize == 0);
}

void initMap(vector<vector<int>> &map){
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map.size();j++)
        map[i][j]=0;
    }
}