#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int INF = 1000000001;
vector<pair<int, int>> edge[20001];
int d[20001] = { 0 };

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		//이부분 까먹음
		if (d[current] != weight) 
			continue;
		else {
			for (int i = 0; i < edge[current].size(); i++) {
				int next = edge[current][i].first;
				int next_w = weight + edge[current][i].second;
				if (d[next] > next_w) {
					d[next] = next_w;
					pq.push(make_pair(-next_w, next));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int v, e, st;
	cin >> v >> e >> st;
	//거리 초기화
	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}
	//간선 정보 추가
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
	}

	dijkstra(st);

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) 
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
}
