// 프로그래머스 
// 레벨 2 문제
// 이따위로도 풀리네 입문편_1
// 아니 그보다 
// 코딩 테스트 문제를 N^2 로 풀었는데
// 왜 이게 정답인가... 

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;


    for(int i = 0; i < prices.size(); i++){
        bool flag = true;
        int j = i;
        for(j = i; j < prices.size(); j++){
           if(prices[i] > prices[j] ){
               flag = false;
               break;
           }
        }
      if(flag){
          answer.push_back(prices.size()-i-1);
      }else{
          answer.push_back(j-i);
     } 
    }


    return answer;
}
