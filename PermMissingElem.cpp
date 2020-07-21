//https://app.codility.com/demo/results/training7HNY7V-X2Y/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int temp = (A.size()+2 )* (A.size()+1)/2;
    int sum =0;
    
    for(int i = 0 ; i < A.size() ; i++){
        sum += A[i];
    }
        
    return temp - sum;
}
