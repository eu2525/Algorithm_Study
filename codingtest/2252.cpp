#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int indegree[32001];
vector<int> student[32001];
queue<int> doit;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int st, en;
		cin >> st >> en;
		student[st].push_back(en);
		indegree[en] += 1;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			doit.push(i);
		}
	}

	while (!doit.empty()) {
		int idx = doit.front();
		cout << idx << " ";
		doit.pop();
		for (int i = 0; i < student[idx].size(); i++) {
			int next = student[idx][i];
			indegree[next] -= 1;
			if (indegree[next] == 0)
				doit.push(next);
		}
	}
}
