#include <iostream>
using namespace std;
#define MAX 1001 * 1001

int cost[1001][3];
int dp[1001][3];
int ans = MAX;

int main() {
	int N;
	cin >> N;
	//Cost 세팅
	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	
	for (int rgb = 0; rgb <= 2; rgb++) { // rgb = 1번 집의 색
		// 1번집에 지정된 색 이외의 색은 MAX로 지정하여 dp할때 선택되지 않도록 함
		for (int i = 0; i <= 2; i++) {
			if (i == rgb)
				dp[1][i] = cost[1][i];
			else
				dp[1][i] = MAX;
		}
		// DP
		for (int i = 2; i <= N; i++) {
			dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
		// 1번집 색과 N번집 색이 겹치지 않게 함
		for (int i = 0; i <= 2; i++) {
			if (i == rgb) continue;
			else ans = min(ans, dp[N][i]);
		}
	}
  
	cout << ans;
}
