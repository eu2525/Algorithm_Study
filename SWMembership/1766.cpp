#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int indegree[32001] = { 0 };
vector<int> problem[32001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int fir, sec;
		cin >> fir >> sec;
		problem[fir].push_back(sec);
		indegree[sec] += 1;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			break;
		}
	}

	int cnt = 0;
	while (cnt < n) {
		int idx = q.front();
		indegree[idx] = -1; // 방문했음을 표시
		cout << idx << " ";
		q.pop();
		cnt += 1;
	
		for (int i = 0; i < problem[idx].size(); i++) {
			int y = problem[idx][i];
			indegree[y] -= 1;
		}

		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				break;
			}
		}
	}

	return 0;
}
