#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	N = 1000 - N;
	int cnt = 0;
	cnt += N / 500;
	N = N % 500;
	cnt += N / 100;
	N = N % 100;

	cnt += N / 50;
	N = N % 50;

	cnt += N / 10;
	N = N % 10;

	cnt += N / 5;
	N = N % 5;

	cnt += N / 1;
	
	cout << cnt << '\n';


}
