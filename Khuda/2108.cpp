#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> num;
int cnt[8001] = { 0 };

int main() {
	int N;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		num.push_back(a);
		sum += a;
		cnt[a + 4000] += 1;
	}
	sort(num.begin(), num.end());

	// 산술평균
	int mean = round((float)sum / N);
	cout << mean << '\n';
	
	// 중앙값
	cout << num[N / 2] << '\n';
	
	// 최빈값
	bool first = false;
	int max_count = 0;
	int max_num = -4001;
	
	for (int i = 0; i < N; i++) {
		int idx = num[i];
		int b = cnt[idx+4000]; //횟수

		if (max_count < b) {
			first = false;
			max_num = idx;
			max_count = b;
		}
		else if (max_count == b) {
			if (first == false && idx != max_num) {
				first = true;
				max_num = idx;
			}
		}
	}
	cout << max_num << '\n';

	//범위 출력
	cout << num.back()  - num.front() << '\n';
}
