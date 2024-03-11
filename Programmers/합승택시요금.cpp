#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dist[201][201] = {0};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for(int i = 0; i <=n; i++){
        for(int j = 0;j <= n; j++){
            if(i != j)
               dist[i][j] = 20000001;
        }
    }
    
    for(int i = 0; i < fares.size(); i++){
        int st = fares[i][0];
        int tg = fares[i][1];
        int w = fares[i][2];
        dist[st][tg] = w;
        dist[tg][st] = w;
    }
    
    for(int k = 1; k <=n ; k++){
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <=n ; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int min_num = 20000001;
    for(int i = 1; i <= n; i++){
        min_num = min(min_num, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return min_num;
}



/*
vector<pair<int,int>> road[201];  // y, 비용 저장
int d[201] ={0}; 
int d_co[201] = {0};

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int current_fee = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(current_fee > d[current])
            continue;
        for(int i = 0; i < road[current].size(); i++){
            int next_fee = road[current][i].second + current_fee;
            int next = road[current][i].first;
            if(d[next] > next_fee){
                d[next] = next_fee;
                pq.push(make_pair(-next_fee, next));
            }
        }
    }
}

void dijkstra_copy(int start){
    d_co[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int current_fee = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(current_fee > d_co[current])
            continue;
        for(int i = 0; i < road[current].size(); i++){
            int next_fee = road[current][i].second + current_fee;
            int next = road[current][i].first;
            if(d_co[next] > next_fee){
                d_co[next] = next_fee;
                pq.push(make_pair(-next_fee, next));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++){
        d[i] = 30000001;
    }
    
    for(int i = 0 ; i < fares.size(); i++){
        int st = fares[i][0];
        int tg = fares[i][1];
        int w = fares[i][2];
        road[st].push_back(make_pair(tg,w));
        road[tg].push_back(make_pair(st,w));
    }
    
    dijkstra(s);
    
    int min_num = d[a] + d[b];
    
    for(int i = 1; i <= n; i++){
        int start_fee = d[i];
        for(int j = 1; j <= n; j++){
            d_co[j] = 300000001;
        }
        dijkstra_copy(i);
        if(min_num > start_fee + d_co[a]+ d_co[b] && d_co[a] != 300000001 && d_co[b] != 300000001 ){
            min_num = start_fee + d_co[a]+ d_co[b];
        }
    }
    
    answer = min_num;
    
    return answer;
}
*/
