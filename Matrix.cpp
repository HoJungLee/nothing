/*
  행렬의 덧샘과 곱샘 구현
 */

#include <iostream>
#include <vector>
#include <thread>

using namespace std;


void multi(vector<vector<int>> A, vector<vector<int>> B,vector<vector<int>> *C){
    int row=A.size();
    int col=B.size();
    
    for(int i =0 ; i<row;i++){
        for(int j=0;j<col; j++){
            for(int k=0; k<col; k++){
                (*C)[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

/*
 행렬의 곱샘은 i행 j의 연산이 다른 n행 m열 정보를 변경하지 않는다.
 그래서 어떤 행에 대해서 연산을 수행하게 되는지를 함수 인자값으로 넘겨 받아 수행 될 수 있게 하였다.
 */

void multi_thread(vector<vector<int>> A, vector<vector<int>> B,vector<vector<int>> *C,int th){
    int i= th;
    int col=B.size();
    
    
        for(int j=0;j<col; j++){
            for(int k=0; k<col; k++){
                (*C)[i][j]+=A[i][k]*B[k][j];
            }
        }
    
}




void disp(vector<vector<int>> C){
    int row=C.size();
    int col=C[0].size();
    
    cout<<"결과"<<endl;
    for(int i=0; i<row ; i++){
        for(int j=0;j<col; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}


// 덧샘
void add(vector<vector<int>> A, vector<vector<int>> *B){
    int row=A.size();
    int col=B[0].size();
    
    for(int i=0; i<row;i++){
        for(int j=0; j<col;j++){
            (*B)[i][j]+=A[i][j];
        }
    }
    
}

void add_thread(vector<vector<int>> A, vector<vector<int>> *B , int i){
    int col=B[0].size();
    
        for(int j=0; j<col;j++){
            (*B)[i][j]+=A[i][j];
        }
    
}



int main() {
    
    vector<vector<int>> da={{1,0,-3},{-2,4,1}};
    vector<vector<int>> db={{2,-1},{3,0},{-5,2}};
    vector<vector<int>> dc={{3,-1},{-2,2}};
    vector<vector<int>> dd={{0,0},{0,0}};

    vector<vector<int>> *d=&dd;
    
    int size=da.size();
    
    thread myThread[size];
    
    // 반복문을 통하여 쓰레드를 생성하고 쓰레드 배열의 번호를 함수의 인자로 전달한다.
    for(int i=0;i<size;i++){
    myThread[i] =  thread(multi_thread,da, db,d, i);
    }
    
    for(int i=0;i<size;i++){
        myThread[i].join();
    }
    
    disp(dd);
    
    
    //add(dc,d);
    size=dc.size();
    
    for(int i=0;i<size;i++){
        myThread[i] =  thread(add_thread,dc,d, i);
    }
    
    for(int i=0;i<size;i++){
        myThread[i].join();
    }
    
    disp(dd);
    
    return  0;
}

