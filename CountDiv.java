class Solution {
    public int solution(int A, int B, int K) {
        // write your code in Java SE 8

      int answer = 0;
      int start;
      int last;
 
      if( B < K ){
          return B == 0 ? 1 : 0;
      }
       
      start = A / K;
      last = B / K;

      answer = last - start;

     if( A % K == 0){
            answer++;
        }

     return answer;
    }
}
