#include <iostream>
#include <vector>
using namespace std;

int su[2001] = { 0 };
int dp[2001][2001] = { 0 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> su[i];
		for (int j = 1; j <= i; j++) {
			if (su[j] == su[i]) {
				if (j == i || j == i - 1)
					dp[j][i] = 1;
				else {
					if (dp[j + 1][i - 1] == 1)
						dp[j][i] = 1;
					else
						dp[j][i] = 0;
				}
			}
			else {
				dp[j][i] = 0;
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}
