#include <string>
#include <vector>
#include <iostream>
using namespace std;

int x = 0;
int y = 0;

void find_rc(int br, int ye){
    int total = br + ye;
    for(int i = 1; i <= total; i++){
        for(int j = 1; j <= i; j++){
            if(((i - 2) * (j - 2) == ye) && (i * j == total)){
                x = i;
                y = j;
                return;
            }      
        }
    }
    return;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    find_rc(brown,yellow);
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}
