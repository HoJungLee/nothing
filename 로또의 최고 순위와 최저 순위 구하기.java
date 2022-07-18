import java.util.*;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {0,0};
        
        int countZero = 0;
        int countSame = 0;
        
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
   
        int i;
        
        
        for( i = 0; i < lottos.length; i++ ){
            if( lottos[i] == 0 ){
               countZero++; 
            }
            map.put( win_nums[i] , 0 );
        }
        
        for( i = 0; i < lottos.length; i++ ){
            if( map.containsKey( lottos[i] ) ){
                countSame++;
            }
        }
        
       i = 7-countSame;
       answer[1] = i < 6 ? i : 6 ;
       i = 7-countSame - countZero ;
       answer[0] = i < 6 ? i : 6 ;
        
       return answer;
    }
}
