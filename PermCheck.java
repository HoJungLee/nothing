// https://app.codility.com/demo/results/trainingGFX6Z8-96K/


// you can also use imports, for example:
 import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        HashSet<Integer> intSet = new HashSet<Integer>(); 
        int i;
        int max = 0;
        for( i = 0; i<A.length; i++){
            intSet.add(A[i]);
            if( max < A[i] ){
                max = A[i];
            }
        }

        if( A.length == intSet.size() && max == A.length ){
            i = 1;
        }else{
            i = 0;
        }

        return i;
    }
}
