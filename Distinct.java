// https://app.codility.com/demo/results/training8PTKQB-3UK/

// you can also use imports, for example:
 import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        HashSet<Integer> dis = new HashSet<Integer>();
        
        for( int temp:A){
            dis.add(temp);
        }

        return dis.size();
    }

 }

