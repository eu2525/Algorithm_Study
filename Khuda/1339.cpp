#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int alpha[26] = { 0 };

bool compare(int a, int b) {
	if (a > b) 
		return true;
	else
		return false;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); j++) {
			int idx = a[j] - 'A';
			alpha[idx] += pow(10, a.size() - j - 1);
		}
	}

	sort(alpha, alpha + 26, compare);

	int result = 0;
	int num = 9;

	for (int j = 0; j <= 9; j++) {
		result += num * alpha[j];
		num--;
	}
	cout << result << '\n';
}
