#include <iostream>
#include <vector>
using namespace std;

int arr[101] = { 0 };
int multitab[101] = { 0 };
bool product[101] = { false };

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	int result = 0;
	for (int i = 0; i < k; i++) {
		int crt_product = arr[i];
		//이미 꽂힌 경우.
		if (product[crt_product] == true) {
			continue;
		}
		//빈 콘센트가 있는 경우
		bool finish = false; //빈 콘센트에 꽂았으면 true.
		for (int j = 1; j <= n; j++) {
			if (multitab[j] == 0) {
				product[crt_product] = true;
				multitab[j] = crt_product;
				finish = true;
				break;
			}
		}
		if (finish == false) {
			int pos = 101; //mutitab을 뽑을 자리.
			int idx = -1; //마지막 위치
			for (int j = 1; j <= n; j++) {
				int tmp = 0;
				for (int t = i + 1; t < k; t++) {
					if (multitab[j] == arr[t]) {
						break;
					}
					tmp += 1;
				}
				if (tmp > idx) {
					pos = j;
					idx = tmp;
				}
			}
			product[multitab[pos]] = false;
			product[crt_product] = true;
			multitab[pos] = crt_product;
			result += 1;
		}
	}
	cout << result << '\n';

}
