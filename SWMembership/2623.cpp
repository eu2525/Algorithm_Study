#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int indegree[1001] = { 0 };
vector<int> singer[1001];
queue<int> q;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		vector<int> sunseo;
		for (int j = 0; j < num; j++) {
			int t;
			cin >> t;
			sunseo.push_back(t);
		}
		for (int j = 0; j < sunseo.size() - 1; j++) {
			int x = sunseo[j];
			int y = sunseo[j + 1];
			singer[x].push_back(y);
			indegree[y] += 1;
		}
	}
	// queue에 진입차수가 0인 정점 삽입
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> dag; // 가수의 순서를 담는 vector
	//위상 정렬
	while (!q.empty()) {
		int idx = q.front();
		dag.push_back(idx);
		q.pop();

		for (int i = 0; i < singer[idx].size(); i++) {
			int dy = singer[idx][i];
			indegree[dy] -= 1;
			if (indegree[dy] == 0) {
				q.push(dy);
			}
		}
	}

	// 비순환 방향 그래프인지 확인하는 과정.
	if (dag.size() != n) { 
		cout << 0 << '\n'; // 비순환 방향 그래프가 아니라면 0을 출력
	}
	else {
		for (auto x : dag)
			cout << x << '\n';
	}

}
