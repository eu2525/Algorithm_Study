#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long sum[1000001];

vector<int> solution(vector<int> sequence, int k) {
    
    vector<int> answer;
    
    sum[0] = 0;
    sum[0] = sequence[0];
    
    for(int i = 0; i < sequence.size(); i++){
        sum[i + 1] = sum[i] + sequence[i];
    }
    // 0 1 2 3 4 5 6 7 
    int min_s = 0;
    int min_e = 0;
    int min_cnt = sequence.size() + 1;
    int s = 0;
    int e = 0;
    
    while(s <= e && e <= sequence.size() && s <= sequence.size()){
        if(sum[e] - sum[s] > k){
            s += 1;
        }
        else if(sum[e] - sum[s] < k){
            e += 1;
        }
        else if (sum[e] - sum[s] == k){
            if(min_cnt > e - s){
                min_s = s;
                min_e = e;
                min_cnt = e - s;
            }
            e += 1;
        }
    }
    
    answer.push_back(min_s);
    answer.push_back(min_e - 1);
    
    return answer;
}
