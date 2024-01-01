#include <iostream>
using namespace std;

int tree[501][501] = { 0 };
int dp[501][501] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tree[i][j];
		}
	}
	dp[1][1] = tree[1][1];
	dp[2][1] = tree[2][1] + tree[1][1];
	dp[2][2] = tree[2][2] + tree[1][1];
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tree[i][j];
		}
	}
	
	int max_num = 0;

	for (int i = 1; i <= n; i++) {
		max_num = max(dp[n][i], max_num);
	}
	cout << max_num << '\n';
}