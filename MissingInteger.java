// https://app.codility.com/demo/results/trainingEBA2CJ-H9K/

// you can also use imports, for example:
 import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int i,answer,size,max;
        HashSet<Integer> set = new HashSet<Integer>();

        size = 0;
        answer = 1;
        max = 0;
        int sum, sum2;

        for( i = 0; i < A.length;i++){
            if( A[i] > 0){
                size++;
                set.add(A[i]);
                if( max < A[i]){
                    max = A[i];
                }
            }
        }

        if( size == set.size() && max == set.size() ){
            answer = max + 1;
        }else{
            answer = 0;
            while(true){
                if( set.add(++answer) ){
                    break;
                }
            }
        }

        return answer;
    }
}
