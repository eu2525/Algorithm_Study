#include <iostream>
#include <vector>
using namespace std;

vector<int> per[1002];
int nd[1002]; // 책을 어떤 사람이 점유 했는지! 저장
bool c[1002]; //책이 점유 되었는지

bool dfs(int x) {
	for (int i = 0; i < per[x].size(); i++) {
		int t = per[x][i];
		if (c[t] == true) 
			continue;
		c[t] = true;
		if (nd[t] == 0 || dfs(nd[t])) {
			nd[t] = x;
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		for (int j = 1; j <= m; j++) {
			int a, b;
			cin >> a >> b;
			for (int t = a; t <= b; t++) {
				per[j].push_back(t);
			}
		}
		fill(nd, nd + 1001, 0);
		int ans = 0;

		for (int j = 1; j <= m; j++)
		{
			fill(c, c + 1001, false);
			if (dfs(j)) 
				ans++;
		}
		cout << ans << '\n';

		for (int t = 1; t <= m; t++) {
			per[t].clear();
		}
	}
	return 0;

}
