// https://app.codility.com/demo/results/trainingNKS8DN-MVP/

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int answer = 0;
        int eastCar = 0;

        for( int temp: A){

            if( temp == 0){
                eastCar++;
            }else{
                answer+=eastCar;
            }

            if( answer > 1000000000){
                answer = -1;
                break;
            }

        }
        return answer;

    }
}
