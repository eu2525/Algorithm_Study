#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int start = section[0];
    int end = start + m;
    answer += 1;
    
    for(int i =1 ; i < section.size(); i++){
        if(end <= section[i]){
            start = section[i];
            end = start + m;
            answer += 1;
        }
    }

    return answer;
}
