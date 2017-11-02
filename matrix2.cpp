#include<iostream>
using namespace std;

class Matrix{
    int rows, columns;
    //double *mData=new double[numE];
    public:
    double** matrix;
    Matrix(int,int);
    ~Matrix(){
        delete [] matrix;
    };
    Matrix (const Matrix&);
    setmatrix();
    setvalues();
};

Matrix::Matrix(int x, int y){
    rows=y;
    columns=x;
    matrix=new double*[columns];
    for(int i = 0; i < columns; ++i){
            matrix[i]=new double[rows];
    }
}


Matrix::setmatrix(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix[i][j]=0.0;
            cout<<matrix[i][j]<<endl;
        }
    }
}

Matrix::setvalues(){
    double a;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin >> a;
            matrix[i][j]=a;
        }
    }
}
int main(){

Matrix AA(2,2);
AA.setmatrix();
AA.setvalues();
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          cout<<AA.matrix[i][j] << endl;
        }
    }

cout<< AA.matrix << endl;
return 0;
}
