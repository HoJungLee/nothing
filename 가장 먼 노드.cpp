// 프로그래머스 
// 레벨 3
// 이따위로도 풀리네_N
// 간선 지우는 방법이 있을 텐데 귀찮다.. 


#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0; 
    map<int,int> already;// 연결된 노드 
    vector<int> addNode; // 추가된 간선으로 연결된 노드 번호
    vector<int> nextSearch; // 다음에 탐색할 것;

    nextSearch.push_back(1);
    already[1] = 1;

    while(!nextSearch.empty()){

        // start 부터 연결된 노드의 수를 구하기
        for(int start : nextSearch){
          for(int i = 0; i < edge.size() ; i++){
            if( edge[i][0] == start){
               addNode.push_back(edge[i][1] );
             }else if( edge[i][1] == start){
               addNode.push_back(edge[i][0] );
           }
         }
        }


         nextSearch.clear();

         // 이미 있는 노드는 제외
         for(int a :addNode ){
            if(already[a]==0){
              already[a]=1;
              nextSearch.push_back(a);
            }
          }

          if(nextSearch.size()==0){
              break;
          }else{
              answer = nextSearch.size();
          }     

          addNode.clear();
  }

    return answer;
}
