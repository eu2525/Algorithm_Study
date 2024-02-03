#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 각각의 간선의 정보를 pair를 통해서 저장
vector<pair<int, int>> a[1001]; 
int d[1001]; //각 정점에서의 최소비용

void dijkstra(int start) {
	d[start] = 0; //시작 지점의 비용은 0;
	// priority_queue는 기본적으로 우선 순위가 높은 요소가 먼저 나오는 자료구조
	// priority_queue<pair<int, int>>를 사용하면 두 번째 요소를 기준으로 우선 순위가 결정된다.
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	//가까운 순서대로 처리하기 위해 큐를 이용
	while (!pq.empty()) {
		int current = pq.top().first;
		//짧은 것이 먼저오게 음수화해서 저장.
		int distance = -pq.top().second; //따라서 꺼낼때는 음수화를 풀어줌
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			//선택된 노드의 인접 노드를 탐색
			int next = a[current][i].first;
			//선택된 노드를 거쳐서 인접 노드로 가는 비용
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 저렴하면 업데이트
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	//초기화
	for (int i = 1; i <= n; i++) {
		d[i] = 1000000001;
	}
	//간선 정보 추가
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		a[s].push_back(make_pair(e, w));
	}
	int st, en;
	cin >> st >> en;
	dijkstra(st);

	cout << d[en] << '\n';
}
