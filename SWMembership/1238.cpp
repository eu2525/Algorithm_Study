#include <iostream>
using namespace std;

int dp[1001][1001] = { 0 };
int n, m, x;

int main() {
	cin >> n >> m >> x;
	
	// 연결되지 않은 도로는 1000001로 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 1000001;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		dp[x][y] = w;
	}

	//플로이드 워셜 진행
	for (int k = 1; k <= n; k++) {
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				if (dp[i][k] != 1000001 && dp[k][j] != 1000001) {
					dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
				}
			}
		}
	}

	// 학생들 중 오고 가는 최대 소요시간 찾기
	int max_num = 0;
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			int r = dp[i][x] + dp[x][i];
			max_num = max(max_num, r);
		}
	}

	cout << max_num << '\n';
}
