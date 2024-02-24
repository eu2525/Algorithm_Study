#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cost[3][3] = {{1,1,1},{5,1,1},{25,5,1}}; //곡괭이 비용
vector<pair<int,int>> pi_mi; //5개씩 구간 나눴을 때 최대 비용!
vector<pair<int, int>> line; //각 구간에 어떤 곡괭이 할당되는지 정함

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first > b.first){
        return true;
    }
    else if (a.first == b.first){
        return a.second < b.second;
    }
    return false;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int dia = picks[0];
    int ir = picks[1];
    int st = picks[2];
    
    int pick_mi = (dia+ir+st) * 5;
    
    int mineral_size = minerals.size();
    mineral_size = min(mineral_size, pick_mi);
    
    //구간 별 최대비용 구하기
    for(int i = 0; i < mineral_size; i++){
        int sum = 0;
        for(int t = i; t < min(i + 5, mineral_size); t++){
            string mi = minerals[t];
            if(mi == "diamond"){
                sum += 25;
            }
            else if(mi == "iron"){
                sum += 5;
            }
            else{
                sum += 1;
            }
        }
        pi_mi.push_back(make_pair(sum, i));
        i += 4;
    }
    //비용이 높은 순으로 정렬 -> 좋은 곡괭이를 먼저 사용하기 위함. 
    sort(pi_mi.begin(), pi_mi.end(), compare);
    
    // 비용 순으로 좋은 곡괭이 선정
    for(int i = 0; i< pi_mi.size(); i++){
        if(dia > 0){
            line.push_back(make_pair(pi_mi[i].second, 0));
            dia -= 1;
        }
        else if(ir > 0){
            line.push_back(make_pair(pi_mi[i].second, 1));
            ir -= 1;
        }
        else{
            line.push_back(make_pair(pi_mi[i].second, 2));
            st -= 1;
        }
    }
    
    sort(line.begin(), line.end());
    // 구간에 선정된 곡괭이를 통해 비용 계산
    for(int i = 0; i < mineral_size; i++){
        int gok = line[i/5].second;
        for(int t = i; t < min(i + 5, mineral_size); t++){
            string mi = minerals[t];
            int idx = 0;
            if(mi == "diamond")
                idx = 0;
            else if(mi == "iron")
                idx = 1;
            else
                idx = 2;
            answer += cost[gok][idx];
        }
        cout << answer << '\n';
        i+=4;
    }   
    return answer;
}
