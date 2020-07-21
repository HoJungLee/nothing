/*
https://app.codility.com/demo/results/training5VSWRA-5G9/
오랫만에 다시하는 프로그래밍
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0; 
    int count = 0;
    bool flag = false;
    while(1){
        
        if(N % 2 == 0 && flag){
            count++;
        }else if( N%2 != 0){
            flag = true;
            if(count > answer){
                answer = count;
            }
            count = 0;
        }
        
        N = N >> 1;
        if(N <= 0){
            break;
        }
    }
    
    return answer;
}
