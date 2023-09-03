#include <iostream>
using namespace std;

int sum[100001] = { 0 };
int num[100001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int j = 1; j <= N; j++) {
		sum[j] = sum[j - 1] + num[j];
	}

	for (int t = 0; t < M; t++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}
}
