#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cost[1001] = { 0 };
vector<pair<int, int>> node[1001]; //도착지, 비용

void dijkstra(int start) {
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int current_w = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (current_w > cost[current]) 
			continue;
		for (int j = 0; j < node[current].size(); j++) {
			int next = node[current][j].first;
			int next_w = node[current][j].second;
			if (current_w + next_w < cost[next]) {
				cost[next] = current_w + next_w;
				pq.push({ -(next_w + current_w), next });
			}
		}
	}
}

int main() {
	int n, m; // n : 도시 수 m : 버스 수
	cin >> n >> m; 
	// 버스 정보
	
	for (int i = 1; i <= n; i++) {
		cost[i] = 100000001;
	}

	for (int i = 0; i < m; i++) {
		int st, en, w;
		cin >> st >> en >> w;
		node[st].push_back({ en,w });
	}
	int start_city, target_city;
	cin >> start_city >> target_city;

	dijkstra(start_city);

	cout << cost[target_city] << '\n';
}
