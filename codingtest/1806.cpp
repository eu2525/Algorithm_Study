#include <iostream>
using namespace std;

int num[100001] = { 0 };

int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int st = 0;
	int en = 0;
	int sum = 0;
	int min_leng = 100001;
  
	while (st <= en) {
		if (sum < s) {
			if (en < n) {
				sum += num[en];
				en++;
			}
			else {
				break;
			}
		}
		else {
			min_leng = min(min_leng, en - st);
			sum -= num[st];
			st++;
		}

	}
	if (min_leng == 100001)
		cout << "0" << '\n';
	else
		cout << min_leng << '\n';
}
