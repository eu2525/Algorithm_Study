#include <iostream>
using namespace std;

int LIS[1000001] = { 0 };
int num[1000001] = { 0 };

int idx_bsearch(int k, int index) {
	int lo = 0;
	int hi = index;

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;

		if (LIS[mid] >= k)
			hi = mid;
		else lo = mid + 1;
	}

	return hi;
}


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> num[i];
	}

	LIS[0] = num[0];

	int idx = 0;
	for (int i = 1; i < n; i++) {
		if (LIS[idx] >= num[i]) {
			int min_idx = idx_bsearch(num[i], idx);
			LIS[min_idx] = num[i];
		}
		else if (LIS[idx] < num[i]) {
			idx += 1;
			LIS[idx] = num[i];
		}
	}
	cout << idx + 1 << '\n';
}
