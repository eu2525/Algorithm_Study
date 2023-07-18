#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	while (true) {
		cin >> N;
		int length = N.size();
		if (N == "0")
			break;
		else {
			bool find = true;
			for (int i = 0; i <= (length/2); i++) {
				if (N[i] != N[length - 1 - i]) {
					find = false;
				}
			}
			if (find == true) {
				cout << "yes" << '\n';
			}
			else
				cout << "no" << '\n';
		}
	}
}
