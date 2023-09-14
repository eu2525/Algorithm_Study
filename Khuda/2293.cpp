#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coin;
int dp[10001] = { 0 };

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		coin.push_back(c);
	}
	
	sort(coin.begin(), coin.end());
	
	dp[0] = 1;
	for (int i = 0; i < n; i++) { 
		int start = coin[i];
		for (int j = start; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k] << '\n';
}
