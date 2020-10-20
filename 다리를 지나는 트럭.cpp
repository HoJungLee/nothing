// 프로그래머스
// 레벨 2 
// 이따위로도 풀리네_2

#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // 시간

    vector<int> bridge;

    bridge.assign(bridge_length,0);

    int pop=0;
    int nowWeight = 0;
    int truckIndex =0;
    int truckMaxCount =truck_weights.size();

    while(true){
        // 시간이 흐르다.
        answer++;

        // 트럭이 다리를 다 건나다.
        nowWeight-=bridge[pop];
        bridge[pop] = 0;

        // 트럭이 다리를 건너기 시작하다.
        if( truckIndex != truckMaxCount && nowWeight + truck_weights[truckIndex] <= weight ){
            nowWeight += truck_weights[truckIndex];
            bridge[pop] = truck_weights[truckIndex];
            truckIndex++;
        }

        pop++;
        if(pop == bridge_length){
            pop =0;
        }

        if( truckIndex == truckMaxCount && nowWeight ==0){
            break;
        }
    }

    return answer;
}
