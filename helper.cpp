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

void initMap(vector<vector<char>> &map){
    int mapSize=map.size();
    //setting the map to an empty
    for(int i=0;i<mapSize;i++){
        for(int j=0;j<mapSize;j++)
        map[i][j]=' ';
    }
    map[0][0]='i';

    random_device rd; // Obtain a random seed from the hardware
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    uniform_int_distribution<> dis(0, mapSize-1); //setting generator of random integers

    for(int i=1;i<mapSize;i++){ // for every line
        int monsterPos = dis(gen);
        int blockPos;
        do{
            blockPos = dis(gen);
        }while(blockPos == monsterPos || blockPos+1==monsterPos);
    }


}