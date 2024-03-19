#include <string>
#include <vector>
#include <iostream>
using namespace std;

int xx[10] = {0};
int yy[10] = {0};

string solution(string X, string Y) {
    string answer = "";
    
    for(int i = 0; i < X.size(); i++){
        int a = X[i] - '0';
        xx[a] += 1;
    }
    
    for(int i = 0; i < Y.size(); i++){
        int a = Y[i] - '0';
        yy[a] += 1;
    }
        
    for(int i = 9; i >= 1; i--){
        int cnt = min(xx[i], yy[i]);
        for(int j = 0; j < cnt; j++){
            answer += to_string(i);
        }
    }
    
    if(min(xx[0], yy[0]) != 0){
        if(answer.size() == 0)
            answer = "0";
        else{
            for(int j = 0; j < min(xx[0],yy[0]); j++)
                answer += "0";
        }
    }
    else{
        if(answer.size() == 0)
            answer = "-1";
    }
    
    return answer;
}
