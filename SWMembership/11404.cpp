#include <iostream>
using namespace std;

int dp[101][101] = { 0 };

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dp[i][j] = 10000001;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == 10000001) {
				cout << "0" << " ";
			}
			else
				cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
}
