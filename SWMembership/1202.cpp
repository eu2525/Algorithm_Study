#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
pair<int, int> v_jewerly[300001];
int v_bag[300001];
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> v_jewerly[i].first >> v_jewerly[i].second;
    }
    for (int i = 0; i < k; ++i) {
        cin >> v_bag[i];
    }
    
    sort(v_jewerly, v_jewerly + n);
    sort(v_bag, v_bag + k);

    int idx = 0;
    long long sum = 0;

    for (int i = 0; i < k; i++) {
        while (idx < n && v_bag[i] >= v_jewerly[idx].first) {
            pq.push(v_jewerly[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
}
