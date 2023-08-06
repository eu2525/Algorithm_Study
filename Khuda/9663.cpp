#include <iostream>
using namespace std;

int N;
int col[16];
int cnt = 0;

bool promising(int idx) 
{
    int k = 0;
    bool swt = true;

    while (k < idx && swt) {
        if (col[k] == col[idx] || abs(col[idx] - col[k]) == idx - k)
            return false;
        k++;
    }
    return true;
}


void queens(int row) {
    if (row == N)
        cnt++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[row] = i; 
            if (promising(row)) 
                queens(row + 1);
        }
    }
}

int main() {
	cin >> N;
	queens(0);
	cout << cnt << '\n';
}
