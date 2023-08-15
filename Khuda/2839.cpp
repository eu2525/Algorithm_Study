#include <iostream>
using namespace std;

int N;
int result = 5000;

void sos(int cnt) {
	if (cnt < 0) {
		return;
	}
	else {
		int sum = N - 5 * cnt;
		if (sum % 3 == 0) {
			int count = cnt + (sum / 3);
			result = count;
			return;
		}
		else {
			sos(cnt - 1);
		}
	}
}

int main() {
	cin >> N;
	int start = N / 5;

	sos(start);

	if (result == 5000) 
		cout << "-1" << '\n';
	else 
		cout << result << '\n';

	return 0;
}
