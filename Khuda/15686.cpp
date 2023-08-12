#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> ch_chck; //선택한 치킨집.
int vilage[51][51] = { 0 };
int result = 1e+10;

void dfs(int cnt, int idx) {
	if (cnt == M) {
		int total_min_distance = 0;
		for (int i = 0; i < home.size(); i++) {
			int min_distance = 1000;
			int dx = home[i].first;
			int dy = home[i].second;
			for (int j = 0; j < ch_chck.size(); j++) {
				int cx = ch_chck[j].first;
				int cy = ch_chck[j].second;
				int distance = abs(cx - dx) + abs(cy - dy);
				min_distance = min(min_distance, distance);
			}
			total_min_distance += min_distance;
		}
		result = min(result, total_min_distance);
	}
	else {
		for (int i = idx; i < chicken.size(); i++) {
			ch_chck.push_back(chicken[i]);
			dfs(cnt + 1, i + 1);
			ch_chck.pop_back();
		}
	}
}

int main() {
	//시간초과때문에 넣음.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				home.push_back(make_pair(i, j));
				vilage[i][j] = 1;
			}
			else if (a == 2) {
				chicken.push_back(make_pair(i, j));
				vilage[i][j] = 2;
			}
		}
	}
	dfs(0, 0);
	cout << result << '\n';
}
