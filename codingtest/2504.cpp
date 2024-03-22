#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> a;

int main() {
  string susik;
	cin >> susik;
  
	int answer = 0, temp = 1;
  
	for (int i = 0; i < susik.size(); i++) {
		if (susik[i] == '(') {
			a.push('(');
			temp *= 2;
		}
		else if (susik[i] == ')') {
			if (a.empty() || a.top() != '(') {
				answer = 0;
				break;
			}
			else if (susik[i-1] == '(') {
				answer += temp;
				temp /= 2;
				a.pop();
			}
			else {
				temp /= 2;
				a.pop();
			}
		}
		else if (susik[i] == '[') {
			a.push('[');
			temp *= 3;
		}
		else if (susik[i] == ']') {
			if (a.empty() || a.top() != '[') {
				answer = 0;
				break;
			}
			else if (susik[i - 1] == '[') {
				answer += temp;
				temp /= 3;
				a.pop();
			}
			else {
				temp /= 3;
				a.pop();
			}
		}
	}

	if (!a.empty())
		answer = 0;

	cout << answer << '\n';
}
