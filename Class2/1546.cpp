#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	float result = 0;
	float max_num = 0;
	for (int i = 0; i < N; i++) {
		float a;
		cin >> a;
		result += a;
		max_num = max(max_num, a);
	}

	result = (result / max_num) * 100;

	cout << (result / N) << '\n';
}