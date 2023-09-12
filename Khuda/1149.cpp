#include <iostream>
using namespace std;

int RGB[1001][3] = { 0 };
int sum[1001][3] = { 0 };

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	sum[0][0] = RGB[0][0];
	sum[0][1] = RGB[0][1];
	sum[0][2] = RGB[0][2];

	for (int i = 1; i < N; i++) {
		sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + RGB[i][0];
		sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + RGB[i][1];
		sum[i][2] = min(sum[i - 1][1], sum[i - 1][0]) + RGB[i][2];
	}

	cout << min(sum[N - 1][0], min(sum[N - 1][1], sum[N - 1][2]));
}
