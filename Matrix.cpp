/*
  행렬의 덧샘과 곱샘 구현
 */

#include <iostream>
#include <vector>
#include <thread>

using namespace std;



class Matrix{ // 행렬 정보를 저장하고 수행 할 객체
    vector< vector <int> > mat;// 행렬 정보를 저장할 벡터
    int row,col;
public:
    Matrix(int row=1,int col=1){
        this->row=row;
        this->col=col;
        this->matrixResize(row,col);
    }
    
    
    Matrix(vector< vector <int> > mat){
        this->row=mat.size();
        this->col=mat[0].size();
        this->insert(mat);
    }
    
    void matrixResize(int row,int col);
    void insert( vector< vector<int>> at );
    void print();
    void matrix_add(Matrix &B);
    void matrix_multiplication(Matrix &B,Matrix &C);
    
    int& getCol(){return col;}
    int& getRow(){return row;}
    void setRow(int row){this->row=row;}
    void setCol(int col){this->col=col;}
    void setMat(vector<vector<int>> mat){this->mat=mat;}
    vector<vector<int>> getMat(){return mat;}
};


void Matrix::matrixResize(int row, int col){
    mat.resize(row,vector<int>(col));
}


void Matrix::insert(vector< vector<int>> at){
 
    for(int i=0; i<this->row;i++){
        for(int j=0; j<this->col;j++){
                this->mat[i][j]=at[i][j];
        }
    }
}


void Matrix::print(){
    for(int i=0; i< this->row ;i++){
        for(int j=0; j< this->col; j++){
            cout<<this->mat[i][j]<<" ";
        }
        cout<<endl;
    }
}



/*
 행렬의 덧샘
 1.행렬의 덧샘은 덧샘에 사용될 행렬의 크기가 서로 같아야 한다.
 2.행렬 A+B를 수행할 때 행렬 A의 i행j열에 수와 B의 i행 j열의 수를 더 한다.
 */

void Matrix::matrix_add(Matrix &B){
    if(this->row!=B.row || this->col!= B.col){
        cout<<"덧샘 불가능"<<endl;
    }else{
        cout<<endl;
        for(int i=0; i< this->row ;i++){
            for(int j=0; j< this->col; j++){
                this->mat[i][j]+=B.mat[i][j];
            }
        }
        this->print();
    }
}
/*
  행렬의 곱샘
 A*B 일때
  1.A 행렬의 열과 B의 행의 길이는 같아야 한다.
  2.A i행과 B의 j열의 수를 각각 곱한 값들을 더하여 결과 행렬의 i행 j열이 된다.
 */
void Matrix::matrix_multiplication(Matrix &B, Matrix &C){
    if(this->col!=B.row){
        cout<<"곱생 불가능"<<endl;
    }else{
        C.matrixResize(this->row, B.col);
        C.col=B.col;
        C.row=this->row;
        cout<<"곱샘한 행렬"<<endl;
        for(int i=0; i<this->row ; i++){
            for(int j=0;j<B.col; j++){
                for(int k=0; k<this->col; k++){
                    C.mat[i][j]+=this->mat[i][k]*B.mat[k][j];
                }
            }
        }
        C.print();
    }
}


/*
  행렬의 곱샘은 i행 j의 연산이 다른 n행 m열 정보를 변경하지 않는다.
  그래서 어떤 행에 대해서 연산을 수행하게 되는지를 함수 인자값으로 넘겨 받아 수행 될 수 있게 하였다.
 */
void multi(vector<vector<int>> A, vector<vector<int>> B,vector<vector<int>> *C, int th){
    int i=th;
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
    
    cout<<"쓰레드를 나누어서 수행한 결과"<<endl;
    for(int i=0; i<row ; i++){
        for(int j=0;j<col; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main() {
    
    Matrix ma(2,3);
    Matrix mb(3,2);
    Matrix mc(2,2);
    Matrix result(2,2);
     
    vector<vector<int>> da={{1,0,-3},{-2,4,1}};
    vector<vector<int>> db={{2,-1},{3,0},{-5,2}};
    vector<vector<int>> dc={{3,-1},{-2,2}};
    vector<vector<int>> dd={{0,0},{0,0}};
    
    ma.insert(da);
    mb.insert(db);
    mc.insert(dc);
    
    cout<<"행렬 A"<<endl;
    ma.print();
    cout<<"\n행렬 B"<<endl;
    mb.print();
    cout<<"\n행렬 C"<<endl;
    mc.print();
    
    cout<<"\nA와 B를 ";
    ma.matrix_multiplication(mb, result);
    cout<<"\n결과에 C를 더한 행렬";
    result.matrix_add(mc);
    
    vector<vector<int>> * d = &dd;
    
    // thread 객체를 생성한다.
    thread one(multi,da, db, d, 0); // 함수 , 행렬 A, 행렬 B, 저장할 행렬 포인터 , 선택한 행
    thread two(multi,da, db, d, 1);
    
    
    // 쓰레드가 모두 수행된 뒤 다음이 실행 될수 있도록 한다.
    one.join();
    two.join();
    disp(dd);
    
 
    
    return  0;
}
