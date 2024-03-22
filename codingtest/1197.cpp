#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001] = { 0 };
vector<pair<long long, pair<int, int>>> node;

int find_parent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find_parent(parent[x]);
}

int main() {
	int v, e;
	cin >> v >> e;
	
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int st, en;
		long long w;
		cin >> st >> en >> w;
		node.push_back({ w,{st,en} });
	}

	sort(node.begin(), node.end());

	int idx = 0;
	int cnt = 0;
	long long result = 0;
	while (cnt < v - 1) {
		int start = node[idx].second.first;
		int end = node[idx].second.second;
		long long w = node[idx].first;
		int p = find_parent(start);
		int q = find_parent(end);
		if (p != q) {
			parent[p] = q;
			result += w;
			cnt += 1;
		}
		idx += 1;
	}

	cout << result << '\n';
}
