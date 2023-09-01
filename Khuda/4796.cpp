#include <iostream>
using namespace std;

int main() {
	int cnt = 1;
	while (true) {
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;

		int whole_day = V / P;
		V = V % P;
		int result = 0;
		if (V > L) {
			result = whole_day * L + L;
		}
		else {
			result = whole_day * L + V;
		}
		cout << "Case " << cnt << ": " << result << '\n';
		cnt += 1;
	}
}

