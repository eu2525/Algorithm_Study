#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int friend_total_cnt[51];
int friend_to_friend[51][51];
int result[51];
map<string, int> p;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    //이름 부르면 바로 index를 뽑을 수 있게...
    for(int i = 0; i < friends.size(); i++){
        p.insert({friends[i], i});
    }
    for(int i = 0; i < gifts.size(); i++){
        string for_you = gifts[i];
        string name;
        int start_idx = 0;
        int end_idx = 0;
        for(int j = 0; j < for_you.size();j++){
            if(for_you[j] == ' '){
                start_idx = p[name];
                friend_total_cnt[start_idx] += 1;
                name = "";
            }
            else{
                name += for_you[j];
            }
        }
        end_idx = p[name];
        friend_total_cnt[end_idx] -= 1;
        friend_to_friend[start_idx][end_idx] += 1; //start가 end에게 준 갯수
        friend_to_friend[end_idx][start_idx] -= 1;
    }
    
    for(int i = 0; i < friends.size(); i++){
        for(int j = i+1; j <friends.size();j++){
            if(friend_to_friend[i][j] == 0){
                if(friend_total_cnt[i] > friend_total_cnt[j]){
                    result[i] += 1;
                }
                else if(friend_total_cnt[i] < friend_total_cnt[j]){
                    result[j] += 1;
                }
            }
            else{
                if(friend_to_friend[i][j] < 0){
                    result[j] += 1;
                }
                else if(friend_to_friend[i][j] > 0)
                    result[i] += 1;
            }
        }
    }
    
    for(int i = 0; i< friends.size(); i++){
        answer = max(answer, result[i]);
    }
    
    return answer;
}
