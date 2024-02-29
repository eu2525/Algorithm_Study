#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<pair<int,int>,int>> node; // ((x,y), index)
vector<int> pre_node;
vector<int> post_node;

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.first.first < b.first.first;
}

void pre_dfs(vector<pair<pair<int,int>,int>> a){
    int max_y = 0;
    int split_idx = 0;
    if(a.size() == 1){
        pre_node.push_back(a[0].second);
        return;
    }
    else{
        for(int i = 0; i < a.size(); i++){
            if(max_y < a[i].first.second){
                max_y = a[i].first.second;
                split_idx = i;
            }
        }
        pre_node.push_back(a[split_idx].second);
        cout << a[split_idx].second << " ";
        vector<pair<pair<int,int>,int>> slice1;
        vector<pair<pair<int,int>,int>> slice2;
        for(int i = 0; i < split_idx; i++){
            slice1.push_back(a[i]);
        }
        for(int j = split_idx+1; j < a.size(); j++){
            slice2.push_back(a[j]);
        }
        if(slice1.empty() == false){
            pre_dfs(slice1);
        }
        if(slice2.empty() == false){
            pre_dfs(slice2);
        }
    }
}

void post_dfs(vector<pair<pair<int,int>,int>> a){
    int max_y = 0;
    int split_idx = 0;
    if(a.size() == 1){
        post_node.push_back(a[0].second);
        return;
    }
    else{
        for(int i = 0; i < a.size(); i++){
            if(max_y < a[i].first.second){
                max_y = a[i].first.second;
                split_idx = i;
            }
        }
        cout << a[split_idx].second << " ";
        vector<pair<pair<int,int>,int>> slice1;
        vector<pair<pair<int,int>,int>> slice2;
        for(int i = 0; i < split_idx; i++){
            slice1.push_back(a[i]);
        }
        for(int j = split_idx+1; j < a.size(); j++){
            slice2.push_back(a[j]);
        }
        if(slice1.empty() == false){
            post_dfs(slice1);
        }
        if(slice2.empty() == false){
            post_dfs(slice2);
        }
        post_node.push_back(a[split_idx].second);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < nodeinfo.size(); i++){
        node.push_back(make_pair(make_pair(nodeinfo[i][0], nodeinfo[i][1]), i+1));
    }
    
    sort(node.begin(),node.end(),compare);

    pre_dfs(node);
    post_dfs(node);
    
    answer.push_back(pre_node);
    answer.push_back(post_node);
    
    return answer;
}
