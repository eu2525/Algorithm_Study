#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

//x^2 + y^2 이 r1^2 보다는 크고 r^2보다는 작으면 됨....
long long solution(int r1, int r2) {
    long long answer = 0;
    long long square_r1 = (long long)r1 * r1;
    long long square_r2 = (long long)r2 * r2;
    
    for(int y = 0; y < r1; y++){
        long long new_r1 = ceil(sqrt(square_r1 - (long long) y * y));
        long long new_r2 = floor(sqrt(square_r2 - (long long) y * y));
        if(y == 0){
            answer += 2 * (new_r2 - new_r1 + 1); 
        }
        else {
            answer += 4 * (new_r2 - new_r1 + 1);            
        }
    }
    
    for(int y = r1; y < r2; y++){
        long long new_r2 = floor(sqrt(square_r2 - (long long) y * y));
        answer += (4 *(new_r2) + 2);
    }
    
    answer += 2;
    
    return answer;
}
