#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int minus_num = 6;
	int cnt = 1;
	while (n > 1) {
		n -= minus_num;
		minus_num += 6;
		cnt += 1;
	}
	cout << cnt << '\n';
}
