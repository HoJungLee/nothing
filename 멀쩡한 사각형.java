/*
프로그래머스 연습
*/

class Solution {
    public long solution(int w, int h) {
        long answer = (long) w * (long) h;
        int temp;
        int perH;
        int perW;
        
        // 항상 높이가 크도록 하기
        if( w > h ){
            temp = h;
            h = w;
            w = temp;
        }
        
        // 공약수 받기
        temp = gongYakSu( w,h);
        
       perH = h / temp;
       perW = w / temp;
        
        
       return answer - ( temp * ( perH + perW -1  ) );
    }
    
    public int gongYakSu( int w , int h){
        int i;
        for( i = w ; i >= 1 ; i-- ){
            if( w % i == 0 && h % i == 0){
                break;
            }
        }
        return i;
    }
}
