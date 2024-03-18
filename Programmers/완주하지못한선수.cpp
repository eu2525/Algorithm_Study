#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// map보다 unordered_map이 key에 대한 Value를 찾는데 시간이 더 적게걸림.
unordered_map<string,int> mp;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i = 0; i < participant.size(); i++){
        mp[participant[i]] += 1;
    }
    
    for(int i = 0; i < completion.size(); i++){
        mp[completion[i]] -= 1;
    }
    
    for(auto player : participant){
        if (mp[player] > 0) {
            answer = player;
            break;
        }
    }
    
    return answer;
}
