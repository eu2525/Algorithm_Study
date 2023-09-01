#include <iostream>
using namespace std;

pair<int, int> fibo[41];


int main() {
	int T;
	cin >> T;
	//fibo 배열 만들기
	fibo[0].first = 1;
	fibo[0].second = 0;
	fibo[1].first = 0;
	fibo[1].second = 1;
	for (int i = 2; i <= 40; i++) {
		fibo[i].first = fibo[i - 1].first + fibo[i - 2].first;
		fibo[i].second = fibo[i - 1].second + fibo[i - 2].second;
	}



	for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
		cout << fibo[num].first << ' ' << fibo[num].second << '\n';
	}
}