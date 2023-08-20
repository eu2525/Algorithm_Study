#include <iostream>
using namespace std;

int main() {
	int A, B;
	int cnt = 0;
	bool find = false;
	cin >> A >> B;
	while (B >= A) {
		if (A == B) {
			find = true;
			break;
		}
		else {
			if (B % 2 == 0) {
				B /= 2;
				cnt += 1;
			}
			else {
				if (B % 10 == 1) {
					B = B / 10;
					cnt += 1;
				}
				else {
					break;
				}
			}
		}
	}

	if (find == true)
		cout << cnt + 1 << '\n';
	else
		cout << "-1" << '\n';
        
}
