#include <iostream>
#include <vector>;
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int,pair<int, int>>> app;
int dp[101][10001] = { 0 };

int main() {
	cin >> n >> m;
	int mem[101] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> mem[i];
	}
	int sum = 0;
	int cost[101] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0; i < n; i++) {
		int c = cost[i];
		int memory = mem[i];
		if (c != 0) {
			app.push_back(make_pair(memory / c, make_pair(c, memory)));
		}
		else {
			app.push_back(make_pair(0, make_pair(c, memory)));
		}
	}

	sort(app.begin(), app.end()); // 

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			// if (j == 0) dp[i][j] = 0; -> 이거 때문에 0인 애들이 집계가 안된거구만....
			if (app[i - 1].second.first <= j) {
				dp[i][j] = max(app[i - 1].second.second + dp[i - 1][j - app[i - 1].second.first], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int j = 0; j <= sum; j++) {
		if (dp[n][j] >= m) {
			cout << j << '\n';
			break;
		}
	}
}
