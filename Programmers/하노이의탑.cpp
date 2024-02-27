#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> answer;

void hanoi(int start, int end, int target, int cnt){
    if(cnt == 1){
        answer.push_back({start, target}); 
    }
    else{
        hanoi(start, end, 6 - (start+target), cnt-1);
        answer.push_back({start, target}); 
        hanoi(6 - (start+target), end, target, cnt - 1);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(1,3,3,n);
    return answer;
}
