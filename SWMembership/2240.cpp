#include <iostream>
using namespace std;

int drop_position[1001];
int dp[1001][31]; //시간, 움직인 횟수

int main() {
	int t, w;
	cin >> t >> w;
  
	for (int i = 1; i <= t; i++) {
		cin >> drop_position[i];
	}

	for (int i = 1; i <= t; i++) {
		int drop_pos = drop_position[i];
		for (int j = 0; j <= w; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k]);
			}
			if (drop_pos == 1 && j % 2 == 0) {
				// 현재 위치가 1에 있고, 사과의 위치가 1인 경우
				dp[i][j] += 1;
			}
			else if (drop_pos == 2 && j % 2 == 1) {
				// 현재 위치가 2에 있고, 사과의 위치가 2인 경우
				dp[i][j] += 1;
			}
		}
	}

	int max_num = 0;
	for (int i = 0; i <= w; i++) {
		max_num = max(dp[t][i], max_num);
	}

	cout << max_num << '\n';

}
