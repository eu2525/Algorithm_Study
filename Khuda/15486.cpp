#include <iostream>
using namespace std;

int consult[1500001][2] = {0};
int dp[1500001] = { 0 };

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> consult[i][0] >> consult[i][1];
	}

	int current_max = 0;
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		// 현재 dp값이 이전 dp값의 최대보다 작은 경우 갱신
		if (dp[i] > current_max) {
			current_max = dp[i];
		}
		else {
			dp[i] = current_max;
		}
		// next_day = 상담 끝나는 날
		int next_day = i + consult[i][0];
		if (next_day > N + 1) {
			continue;
		}
		else {
			if (dp[next_day] < dp[i] + consult[i][1]) 
				dp[next_day] = dp[i] + consult[i][1];
		}
	}

	int max_num = 0;
	for (int i = 1; i <= N + 1; i++) {
		max_num = max(max_num, dp[i]);
	}
	cout << max_num << '\n';
}
