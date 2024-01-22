#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[1001] = { 0 }; // 진입차수
int cost[1001] = { 0 }; // 건물 건설 비용
int result[1001] = { 0 }; //그 노드에 도달하는데 필요한 총 비용

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, k;
		cin >> n >> k;
		//건물 건설 비용
		for (int j = 1; j <= n; j++) {
			cin >> cost[j];
			result[j] = cost[j];
		}

		vector<int> build[1001]; // node에 대한 배열
		// 건물 규칙
		for (int j = 0; j < k; j++) {
			int st, en;
			cin >> st >> en;
			build[st].push_back(en);
			indegree[en] += 1;
		}

		int w;
		cin >> w;
		
		queue<int> q;
		// 진입차수가 0인 노드를 queue에 넣음.
		for(int j = 1; j <= n; j++){
			if (indegree[j] == 0)
				q.push(j);
		}
		//위상정렬 수행
		while (!q.empty()) {
			// idx 노드는 진입차수가 0인 노드.
			int idx = q.front();
			q.pop();
			// idx노드와 연결된 노드들 탐색
			for (int j = 0; j < build[idx].size(); j++) {
				int dy = build[idx][j]; //idx 노드와 연결된 노드
				result[dy] = max(result[dy], result[idx] + cost[dy]);
				indegree[dy] -= 1;
				if (indegree[dy] == 0)
					q.push(dy);
			}
		}

		cout << result[w] << '\n';

		//초기화
		for (int j = 1; j <= n; j++) {
			indegree[j] = 0;
			cost[j] = 0;
			result[j] = 0;
		}
	}
}
