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