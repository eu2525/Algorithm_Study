#include <iostream>
using namespace std;

int nc2(int n , int m) {
	if (m == 0 || m == n) return 1;
	else return nc2(n - 1, m - 1) + nc2(n - 1, m);
}

int main() {
	int N, M;
	cin >> N >> M;

	int result = nc2(N, M);
	cout << result << '\n';
}
