#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
    
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		int max_ab = max(a, b);
		int min_ab = min(a, b);
		int max_num = max(max_ab, c);
		int middle_num = min(max_ab, c);

		if ((min_ab*min_ab) + (middle_num*middle_num ) == max_num *max_num) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
	}
}
