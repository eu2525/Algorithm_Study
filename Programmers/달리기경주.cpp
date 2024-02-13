#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<string, int> myMap;

vector<string> solution(vector<string> players, vector<string> callings) {
  
    for(int i = 0; i < players.size(); i++){
        myMap.insert(pair<string, int>(players[i], i));
    }
    
    for(int i = 0; i < callings.size(); i++){
        int idx = myMap[callings[i]];
        string p_player = players[idx - 1];
        swap(players[idx], players[idx - 1]);
        myMap[callings[i]] -= 1;
        myMap[p_player] += 1;
    }
    
    return players;
}
