#include <string>
#include <vector>
#include <iostream>
using namespace std;

int min_x, min_y;
int max_x = 0, max_y = 0;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int row_num = wallpaper.size();
    int col_num = wallpaper[0].size();
    min_x = row_num;
    min_y = col_num;
    for(int i = 0; i < row_num; i++){
        for(int j = 0; j < col_num; j++){
            if(wallpaper[i][j] == '#'){
                min_x = min(min_x , i);
                min_y = min(min_y , j);
                max_x = max(max_x, i);
                max_y = max(max_y, j);
            }
        }
    }
    answer.push_back(min_x);
    answer.push_back(min_y);
    answer.push_back(max_x + 1);
    answer.push_back(max_y + 1);
    
    return answer;
}
