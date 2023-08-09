#include <iostream>
using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;

	long long max_idx = K;
	long long min_idx = 1;
	long long result = 0;
	while (min_idx <= max_idx) {
		int mid = (max_idx + min_idx) / 2;
		long long temp = 0;
		for (long long i = 1; i <= N; i++) {
			temp += min(mid / i, N);
		}
		if (temp >= K) {
			result = mid;
			max_idx = mid - 1;
		}
		else {
			min_idx = mid + 1;
		}
	}
	cout << result << '\n';
}
