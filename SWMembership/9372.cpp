#include <iostream>
#include <vector>
using namespace std;

int parent[1001];
vector<pair<int, int>> plane;

int find_parent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find_parent(parent[x]);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		for (int j = 0; j < m; j++) {
			int st, en;
			cin >> st >> en;
			plane.push_back({ st, en });
		}

		int cnt = 0;

		for (int i = 0; i < plane.size(); i++) {
			int x = plane[i].first;
			int y = plane[i].second;
			int fx = find_parent(x);
			int fy = find_parent(y);
			if (fx != fy) {
				parent[fy] = fx;
				cnt += 1;
			}
		}

		cout << cnt << '\n';

		plane.clear();
	}
}
