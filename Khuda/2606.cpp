#include <iostream>
#include <vector>
using namespace std;

bool check[101] = { false };
vector<int> graph[101];

void dfs(int idx) {
	if (check[idx] == false) {
		check[idx] = true;
		int size = graph[idx].size();
		for (int i = 0; i < size; i++) {
			int num = graph[idx][i];
			dfs(num);
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	dfs(1);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i] == true) {
			cnt += 1;
		}
	}
	cout << cnt - 1 << '\n';
}