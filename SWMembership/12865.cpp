#include <iostream>
using namespace std;

int bag[101][500001] = { 0 };

int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		for (int j = 0; j <= k; j++) {
			if (j < w) {
				bag[i][j] = bag[i - 1][j];
			}
			else {
				bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - w] + v);
			}
		}
	}
	int max_value = 0;
	for (int j = 0; j <= k; j++) {
		max_value = max(max_value, bag[n][j]);
	}
	cout << max_value << '\n';
}