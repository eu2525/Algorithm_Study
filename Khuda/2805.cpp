#include <iostream>
using namespace std;

int N, M;
long long max_tree = 0;
long long tree[1000001] = { 0 };

long long binary_search(long long start, long long end) {
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long tree_length = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				long long b = tree[i] - mid;
				tree_length += b;
			}
		} 
		if (tree_length >= M) 
			start = mid + 1; 
		else
			end = mid - 1;
	}

	return end;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		max_tree = max(a, max_tree);
		tree[i] = a;
	}

	long long result = binary_search(0, max_tree);
	cout << result << '\n';
	
	return 0;
}
