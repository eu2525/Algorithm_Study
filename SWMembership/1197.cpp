#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int result = 0;
int parent[10001] = { 0 };
vector<pair<int, pair<int, int>>> tree;

int find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	parent[y] = x;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree.push_back(make_pair(c, make_pair(a, b)));
	}
	// 오름차순으로 정렬
	sort(tree.begin(), tree.end());
	
	int cnt = 0;
	int idx = 0;
	// 최소 스패닝 트리 찾기
	while (cnt < n - 1) {
		int w = tree[idx].first;
		int x = tree[idx].second.first;
		int y = tree[idx].second.second;
		int p = find(x);
		int q = find(y);
		if (p != q) { // 서로소 집합인 경우 이어준 다음 집합을 합침
			merge(p, q); // 집합을 합침
			result += w;
			cnt += 1;
		}
		idx += 1;
	}
	cout << result << '\n';
}
