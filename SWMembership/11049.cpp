#include <iostream>
using namespace std;

int n;
int matrix[501][2];
int dp[501][501] = { 0 };


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            dp[j][i + j] = 2147483647;
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}
