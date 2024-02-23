#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mm; // (과목,남은 시간) 저장 최초에만 저장...
stack<pair<string, int>> stk; //(과목, 남은 시간)이 들어가게
vector<pair<int,string>> timeout; // 시작 시간 순으로 저장하기 위해

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    //입력 바꾸기
    for(int i = 0; i < plans.size(); i++){
        string subj = plans[i][0];
        string hour = plans[i][1];
        int sp_time = stoi(plans[i][2]);
        
        int h = stoi(hour.substr(0,2));
        int m = stoi(hour.substr(3,2));
        int new_hour = h * 60 + m; 
        
        timeout.push_back(make_pair(new_hour, subj));
        mm.insert({subj, sp_time});
    }    
    // 시작시간 순으로 정렬
    sort(timeout.begin(), timeout.end());
    
    //
    for(int i = 0; i < timeout.size() - 1; i++){
        string subject = timeout[i].second;
        int dist = timeout[i + 1].first - timeout[i].first;
        if(dist >= mm[subject]){
            int rest_h = dist - mm[subject];
            mm[subject] = 0;
            answer.push_back(subject);
            
            while(!stk.empty() && rest_h > 0){
                pair<string,int> t = stk.top();
                stk.pop();
                if(t.second <= rest_h){
                    rest_h -= t.second;
                    answer.push_back(t.first);
                }
                else{
                    int new_hour = t.second - rest_h;
                    stk.push(make_pair(t.first, new_hour));
                    rest_h = 0;
                }
            }
        }
        else{
            int h = mm[subject] - dist;
            stk.push(make_pair(subject, h));
            mm[subject] = h;
        }
    }
    
    stk.push(make_pair(timeout[timeout.size() - 1].second, 0));
    
    while(!stk.empty()){
        pair<string,int> tk = stk.top();
        answer.push_back(tk.first);
        stk.pop();
    }
    
    

                          
    
    return answer;
}
