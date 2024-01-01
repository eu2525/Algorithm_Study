#include <iostream>
using namespace std;

long long A, B, C;

long long Rule(int A, int B, int C) {
    if (B == 1)
        return A % C;

    long long temp = Rule(A, B / 2, C);

    temp = temp * temp % C;
    
    if (B % 2 == 0) 
        return temp; //Â¦¼ö
    else 
        return temp * A % C; //È¦¼ö

}


int main(void) {
    cin >> A >> B >> C;
    cout << Rule(A, B, C);
    return 0;
}
