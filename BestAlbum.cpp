
// 프로그래머스 해쉬
// 베스트 엘범
// 이따위로도 풀리네 입문편

#include <string>
#include <vector>
#include <map> 

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    vector<int> tempAnswer; // 임시로 답을 저장할 변수


    // map을 이용하여 장르별 우선순위를 구한다.
    map<string,int> sum;
    map<string,int>::iterator iter;
    map<int,string> sumR;
    map<int,string>::iterator iter2;

    for(int i = 0; i < genres.size(); i++){
        sum[genres[i]] += plays[i];
    }

    for(iter = sum.begin(); iter != sum.end(); iter++){
        sumR[(iter->second)*-1] = iter->first;
    }

    sum.clear();
    int gi = 0;

    // 우선순위를 구한 장르별로 2개의 주소 범위를 갖도록 설정해 준다. 
    // 그러니까 map에는 장르, 임시 답에 들어갈 장르별 시작 주소 가 저장된다.
    for(iter2 = sumR.begin(); iter2 != sumR.end(); iter2++){
        sum[iter2->second] = gi;
        gi+=2;
    }


    // 밑으로 임시 답 벡터에 쳐넣기 구간
    tempAnswer.assign(sum.size()*2,-1); // 임시 답 벡터를 -1로 초기화

    // 기준 + 0번 주소에는 가장 큰 값이
    // 기준 + 1번 주소에는 그 다음 값이 저장되므로
    // 0번이 비면 0번에 바로 0번보다 큰 값이 들어오면 0번에 0번에 있던 값은 1번 값보다는 크므로 1번으로 자리를 옮긴다.
    // 0번보다는 작은데 1번이 비면 1번에, 1번 보다는 크면 1번에 저장한다.
    
    for(int i = 0; i < genres.size();i++){
        gi = sum[genres[i]];

        if( tempAnswer[gi] == -1){
            tempAnswer[gi] = i;
        }else if( plays[ tempAnswer[gi] ] < plays[i]){
            tempAnswer[gi+1] = tempAnswer[gi];
            tempAnswer[gi] = i;
        }else if( tempAnswer[gi] == -1){
            tempAnswer[gi+1] = i;
        }else if( plays[ tempAnswer[gi+1] ] < plays[i]){
            tempAnswer[gi+1] = i;
        }
    }

    // 임시 답 벡터에 -1값 지우기 

    for(int i = 0; i < tempAnswer.size(); i++){
        if( tempAnswer[i] != -1){
            answer.push_back(tempAnswer[i]);
        }
    }    
    return answer;
}
