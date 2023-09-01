#include <iostream>
#include <vector>
using namespace std;

vector<int> fd;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int result = i;
		int num = i;
		
		while (num != 0) {
			result += num % 10;
			num /= 10;
		}

		if (result == N) {
			fd.push_back(i);
		}
	}

	if (fd.size() == 0) 
		cout << 0 << '\n';
	else 
		cout << fd[0] << '\n';
}