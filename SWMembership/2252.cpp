#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> student[32001];
int indegree[32001] = { 0 };

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		student[a].push_back(b);
		indegree[b] += 1;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) 
			q.push(i);
	}

	while (!q.empty()) {
		int idx = q.front();
		cout << idx << " ";
		q.pop();

		for (int i = 0; i < student[idx].size(); i++) {
			int dy = student[idx][i];
			indegree[dy] -= 1;
			if (indegree[dy] == 0) {
				q.push(dy);
			}
		}
	}

	return 0;
}
