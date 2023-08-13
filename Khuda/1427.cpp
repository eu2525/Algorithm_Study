#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> num;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	string N;
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		string a = N.substr(i, 1);
		int inta = stoi(a);
		num.push_back(inta);
	}
	sort(num.begin(), num.end(), compare);

	for (auto x : num) {
		cout << x;
	}
}
