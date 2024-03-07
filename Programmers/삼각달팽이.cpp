#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[1001][1001];
vector<pair<pair<int,int>,int>> snail; //level, 값 저장
vector<int> answer;

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.second < b. first.second)
        return true;
    else if(a.first.second == b.first.second){
        if(a.first.first < b.first.first)
            return true;
        else
            return false;
    }
    else
        return false;
}

void rotate(int start, int length, int row, int col){ // 시작값, 길이, 위치
    //length가 0보다 작아지는 경우를 생각하지 못함...
    if(length <= 0){
        if(length == 0)
            snail.push_back(make_pair(make_pair(row,col),start));
        return;   
    }
    else{
        for(int i = 0; i <= length; i++){
            int val = start + i;
            int high =  col + i;
            snail.push_back(make_pair(make_pair(row, high), val));
            visited[row][high] = true;
        }
        for(int i = 1 ; i <= length; i++){
            int val = start + length + i;
            int rw = row + i;
            int high = col + length;
            snail.push_back(make_pair(make_pair(rw,high), val));
            visited[rw][high] = true;
        }
        for(int i =1; i < length; i++){
            int val = start + 2 * length + i;
            int rw = row + length - i;
            int high = col + length - i;
            snail.push_back(make_pair(make_pair(rw,high), val));
            visited[rw][high] = true;
        }
        
        if(visited[row+1][col+2] == true){
            return;
        }
        else
            return rotate(start + 3 * length, length - 3, row + 1, col + 2);
    }
}


vector<int> solution(int n) {
    rotate(1, n - 1, 1, 1);
  
    sort(snail.begin(), snail.end(), compare);
    
    for(auto x : snail){
        answer.push_back(x.second);
    }
    
    return answer;
}
