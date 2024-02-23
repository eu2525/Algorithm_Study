#include <string>
#include <vector>
#include <iostream>
using namespace std;

int mapp[51][51] = {0};
int row_sz = 0;
int col_sz = 0;
int start_x, start_y;

void move(int row,int col, char d , int cnt){
    bool go = true;
    if(d == 'S'){
        if(row + cnt >=0 && row + cnt < row_sz){
            for(int i = row + 1; i <= row + cnt; i++){
                if(mapp[i][col] == 2){
                    go = false;
                    break;
                }
            }
        }
        else
            go = false;
    }
    else if(d == 'N'){
        if(row - cnt >=0 && row - cnt < row_sz){
            for(int i = row - 1; i >= row - cnt; i--){
                if(mapp[i][col] == 2){
                    go = false;
                    break;
                }
            }
        }
        else
            go = false;
    }
    else if (d == 'E'){
        if(col + cnt >=0 && col + cnt < col_sz){
            for(int i = col + 1; i <= col + cnt; i++){
                if(mapp[row][i] == 2){
                    go = false;
                    break;
                }
            }
        }
        else
            go = false;
    }
    else { //d == 'W'
        if(col - cnt >=0 && col - cnt < col_sz){
            for(int i = col - 1; i >= col - cnt; i--){
                if(mapp[row][i] == 2){
                    go = false;
                    break;
                }
            }
        }
        else
            go = false;
    }
    if(go == true){
        if(d == 'S')
            start_x += cnt;
        else if (d== 'N')
            start_x -= cnt;
        else if(d == 'E')
            start_y += cnt;
        else
            start_y -= cnt;
        return;
    }
    else
        return;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    row_sz = park.size();
    col_sz = park[0].size();
    for(int i = 0; i < row_sz; i++){
        for(int j = 0; j < col_sz; j++){
            if(park[i][j] == 'O')
                mapp[i][j] = 0;
            else if(park[i][j] == 'S'){
                start_x = i;
                start_y = j;
                mapp[i][j] = 1;
            }
            else
                mapp[i][j] = 2;
        }
    }
    
    for(int i = 0; i < routes.size(); i++){
        string dir = routes[i];
        char d = dir[0];
        int cnt = dir[2] - '0';
        move(start_x, start_y, d, cnt);

    }
    answer.push_back(start_x);
    answer.push_back(start_y);
    
    return answer;
}
