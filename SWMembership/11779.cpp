#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> city[1001];
vector<int> st;
int root[1001];
int d[1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start));
	d[start] = 0;

	while (!q.empty()) {
		int c_w = -q.top().first;
		int current = q.top().second;
		q.pop();
		if (c_w > d[current])
			continue;
		for (int i = 0; i < city[current].size(); i++) {
			int next = city[current][i].first;
			int next_w = c_w + city[current][i].second;
			if (d[next] > next_w) {
				root[next] = current;
				d[next] = next_w;
				q.push(make_pair(-next_w, next));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d[i] = 987654321;
	}

	for (int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		city[s].push_back(make_pair(e, v));
	}

	int sta, en;
	cin >> sta >> en;

	dijkstra(sta);


	cout << d[en] << '\n';

	int point;
	point = en;

	while (point != sta) { // 역추적
		st.push_back(point);
		point = root[point];
	}
	st.push_back(sta);

	cout << st.size() << '\n';
	for (int i = st.size() - 1; i >= 0; i--) {
		cout << st[i] << ' '; // 경로 출력
	}
}
