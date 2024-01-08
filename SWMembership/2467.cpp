#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, int>> liquid;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		if (a < 0)
			liquid.push_back(make_pair(-1 * a, -1));
		else {
			liquid.push_back(make_pair(a, 1));
		}
	}
	sort(liquid.begin(), liquid.end());
	
	//0에 가까운 인덱스 값 찾기
	long long zero = 2000000000;
	int idx = 0;
	for (int j = 0; j < liquid.size() - 1; j++) {
		int sum = 0;
		if (liquid[j].second != liquid[j + 1].second) {
			sum = abs(liquid[j].first - liquid[j + 1].first);
		}
		else {
			sum = abs(liquid[j].first + liquid[j + 1].first);
		}
		if (sum < zero) {
			zero = sum;
			idx = j;
		}
	}
	// 결과 출력을 위해 오름차순 정렬
	int first_num = liquid[idx].first * liquid[idx].second;
	int second_num = liquid[idx + 1].first * liquid[idx + 1].second;
	if (first_num < second_num) 
		cout << first_num << " " << second_num << '\n';
	else 
		cout << second_num << " " << first_num << '\n';
}
