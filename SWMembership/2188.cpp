#include <iostream>
#include <vector>
using namespace std;

vector<int> cow[201];
int d[201]; //축사에 어떤 소가 들어있는지 소의 번호를 저장
bool c[201]; //축사에 소가 들어있는지 bool 저장

bool dfs(int x) {
	for (int i = 0; i < cow[x].size(); i++) {
		int cow_tg = cow[x][i];
		if (c[cow_tg] == true)
			continue;
		c[cow_tg] = true;
		if (d[cow_tg] == 0 || dfs(d[cow_tg])) {
			d[cow_tg] = x;
			return true;
		}
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int tg;
			cin >> tg;
			cow[i].push_back(tg);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + 201, false);
		if (dfs(i))
			cnt += 1;
	}

	cout << cnt << '\n';

	return 0;
}
