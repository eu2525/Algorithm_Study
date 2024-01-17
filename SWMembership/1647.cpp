#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> map;
int parent[100001] = { 0 };

int parent_find(int a) {
	if (parent[a] == a) 
		return a;
	else 
		return parent[a] = parent_find(parent[a]);
	
}

int main() {
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(map.begin(), map.end());

	int result = 0;
	int cnt = 0;
	int idx = 0;
	while (cnt < n - 2) {
		int x = map[idx].second.first;
		int y = map[idx].second.second;
		int w = map[idx].first;
		int p = parent_find(x);
		int q = parent_find(y);
		if (p != q) {
			result += w;
			parent[p] = q;
			cnt++;
		}
		idx++;
	}

	cout << result << '\n';
}
