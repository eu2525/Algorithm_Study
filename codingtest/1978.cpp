#include <iostream>
using namespace std;

int eratos[1001] = { 0 };

int main() {
	int n;
	cin >> n;
  
	for (int i = 2; i <= 1000; i++) {
		eratos[i] = i;
	}

	for (int i = 2; i <= 1000; i++) {
		if (eratos[i] == 0) continue;
		
    for (int j = 2; i * j <= 1000; j++) {
			eratos[i * j] = 0;
		}
    
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (eratos[a] == a)
			cnt += 1;
	}
	cout << cnt << '\n';
}
