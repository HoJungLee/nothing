//https://app.codility.com/demo/results/trainingZGVMJH-AZJ/
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<bool> road;
    road.resize(X,true);
    int finish = X;
    
   for( int i = 0; i < A.size(); i++){
       
        if( A[i] > X){
           continue;
       }
       
       if( road[A[i]-1]){
           road[A[i]-1] = false;
           finish--;
       }
       
       if( finish == 0){
           return i;
       }
       
   }
    
    return -1;
}
