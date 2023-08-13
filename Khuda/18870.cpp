#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> num;
vector<pair<int, int>> cnt;

bool compare_f(pair<int, int> a, pair<int, int> b) {
	int a_f = a.first;
	int b_f = b.first;
	return a_f < b_f;
}
bool compare_s(pair<int, int> a, pair<int, int> b) {
	int a_s = a.second;
	int b_s = b.second;
	return a_s < b_s;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		num.push_back(make_pair(a, i)); //a는 입력값, i는 원래 출력 순서
	}
	//입력 값을 기준으로 정렬
	sort(num.begin(), num.end(),compare_f);

	cnt.push_back(make_pair(0, num[0].second));
	int j = 0;
	for (int i = 1; i < N; i++)
	{
		if (num[i-1].first == num[i].first)
			cnt.push_back(make_pair(j,num[i].second));
		else {
			j += 1;
			cnt.push_back(make_pair(j, num[i].second));
		}
	}
    // 출력 순서를 기준으로 정렬
	sort(cnt.begin(), cnt.end(), compare_s);

	for (auto x : cnt) {
		cout << x.first << " ";
	}
}
