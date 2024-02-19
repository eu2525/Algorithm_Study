#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<string, int> p;

int photo_sum(vector<string> photo_name){
    int result = 0;
    for(int i = 0; i < photo_name.size(); i++){
        string name = photo_name[i];
        result += p[name];
    }
    return result;
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i = 0; i < name.size(); i++){
        p.insert({name[i], yearning[i]});
    }

    for(int i = 0; i < photo.size(); i++){
        int an = photo_sum(photo[i]);
        answer.push_back(an);
    }

    return answer;
}
