#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> stk;

int main() {
	string ntt;
	cin >> ntt;

	for (int i = 0; i < ntt.size(); i++) {
		char s = ntt[i];
		int asc = s - 'A';
    
		if (asc >= 0 && asc <= 26) {
			cout << s;
		}
		else {
            if (s == '(')
                stk.push(s);
            else if (s == '*' || s == '/')
            {
                while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s);
            }
            else if (s == '+' || s == '-')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s);
            }
            else if (s == ')')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    cout << stk.top();
                    stk.pop();
                }
               stk.pop();
            }
		}
	}
  
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}

  return 0;
}
