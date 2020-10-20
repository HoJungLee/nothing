//프로그래머스 
// 레벨 2 기능개발
// 이건 N이다. 

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day =0;
    int count =0;
    
    for(int i =0; i < progresses.size(); i++){
        if(  progresses[i]+day*speeds[i] >= 100){
            count++;
        }else{
            if( count != 0){
                answer.push_back(count);
                count = 0;
            }
            day = (99-progresses[i])/ speeds[i] + 1; // 
            count++;
        }   
    }
   
    if( count != 0){
        answer.push_back(count);
        count = 0;
    }
    
    return answer;
}
