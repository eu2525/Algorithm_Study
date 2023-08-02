#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

vector<string> command_vec;
ll Stack[1001] = { 0 };
int idx = 0; // 다음에 숫자가 들어갈 칸
int cnt = 0;

bool NUM(string a) {
	ll x = stoi(a); 
	if (x > 1000000000) {
		return false;
	}
	else if (x < -100000000) {
		return false;
	}
	else {
		Stack[idx] = x;
		idx++;
		return true;
	}
}

bool POP() {
	if (idx == 0) {
		return false;
	}
	else {
		Stack[idx - 1] = 0;
		idx--;
		return true;
	}
}

bool INV() {
	if (idx == 0) {
		return false;
	}
	else {
		Stack[idx - 1] *= -1;
		return true;
	}
}
bool DUP() {
	if (idx == 0) {
		return false;
	}
	else {
		Stack[idx] = Stack[idx - 1];
		idx++;
		return true;
	}
}
bool SWP() {
	if (idx < 2) {
		return false;
	}
	else {
		ll sub = Stack[idx - 2];
		Stack[idx - 2] = Stack[idx - 1];
		Stack[idx - 1] = sub;
		return true;
	}
}
bool ADD() {
	if (idx < 2) {
		return false;
	}
	else {
		ll sum = Stack[idx - 2] + Stack[idx - 1];
		if (sum > 1000000000) {
			return false;
		}
		else if (sum < -1000000000) {
			return false;
		}
		else {
			Stack[idx - 2] = sum;
			idx--;
			return true;
		}
	}
}
bool SUB() {
	if (idx < 2) {
		return false;
	}
	else {
		ll sum = Stack[idx - 2] - Stack[idx - 1];
		if (sum > 1000000000) {
			return false;
		}
		else if (sum < -1000000000) {
			return false;
		}
		else {
			Stack[idx - 2] = sum;
			idx--;
			return true;
		}
	}
}
bool MUL() {
	if (idx < 2) {
		return false;
	}
	else {
		ll sum = Stack[idx - 2] * Stack[idx - 1];
		if (sum > 1000000000) {
			return false;
		}
		else if (sum < -1000000000) {
			return false;
		}
		else {
			Stack[idx - 2] = sum;
			idx--;
			return true;
		}
	}
}
bool DIV() {
	if (idx < 2) {
		return false;
	}
	else {
		if (Stack[idx - 1] == 0) {
			return false;
		}
		int neg = 0;
		ll x = Stack[idx - 1];
		ll y = Stack[idx - 2];
		if (x < 0) {
			neg++;
		}
		if (y < 0) {
			neg++;
		}

		ll sum = y / x;
		if (sum > 1000000000) {
			return false;
		}
		else if (sum < -1000000000) {
			return false;
		}
		else {
			if (neg == 1) {
				sum = -(abs(sum));
			}
			else {
				sum = abs(sum);
			}
			Stack[idx - 2] = sum;
			idx--;
			return true;
		}
	}
}
bool MOD() {
	if (idx < 2) {
		return false;
	}
	else {
		if (Stack[idx - 1] == 0) {
			return false;
		}
		ll sum = Stack[idx - 2] % Stack[idx - 1];
		if (sum > 1000000000) {
			return false;
		}
		else if (sum < -1000000000) {
			return false;
		}
		else {
			Stack[idx - 2] = sum;
			idx--;
			return true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		string a;
		cin >> a;
		if (a == "QUIT") {
			return 0;
		}
		else if (a == "END") {
			int N;
			cin >> N;
			for (int i = 0; i < N; i++) {
				cin >> Stack[0]; //cnt는 없음
				idx = 1;

				if (cnt != 0) {
					cout << "ERROR" << '\n';
				}
				else {
					bool tf = true;
					for (int i = 0; i < command_vec.size(); i++) {
						string command = command_vec[i];
						if (command == "NUM") {
							string command_int = command_vec[i + 1];
							tf *= NUM(command_int);
							i += 1;
						}
						else if (command == "POP") {
							tf *= POP();
						}
						else if (command == "INV") {
							tf *= INV();
						}
						else if (command == "DUP") {
							tf *= DUP();
						}
						else if (command == "SWP") {
							tf *= SWP();
						}
						else if (command == "ADD") {
							tf *= ADD();
						}
						else if (command == "SUB") {
							tf *= SUB();
						}
						else if (command == "MUL") {
							tf *= MUL();
						}
						else if (command == "DIV") {
							tf *= DIV();
						}
						else if (command == "MOD") {
							tf *= MOD();
						}

						if (tf == false) {
							break;
						}
					}
					if (tf == true && idx == 1) {
						cout << Stack[0] << '\n';
					}
					else {
						cout << "ERROR" << '\n';
					}

				}
			}
			cnt = 0;
			command_vec.clear();
			cout << '\n';
		}
		else {
			command_vec.push_back(a);
			if (a == "NUM" || a == "DUP") {
				cnt += 1;
			}
			else if (a == "INV" || a == "SWP")
				continue;
			else if (a == "POP" || a == "ADD"||a =="SUB"|| a=="MUL" ||
				a == "DIV" || a == "MOD") {
				cnt -= 1;
			}
		}
	}
}
