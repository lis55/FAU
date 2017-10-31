#include<iostream>
using namespace std;

class Matrix{
    int rows, columns;
    double** matrix;
    public:
    Matrix(int,int);

};

Matrix::Matrix(int x, int y){
    rows=y;
    columns=x;
    matrix=new double*[columns];
    for(int i = 0; i < columns; ++i){
            matrix[i]=new double[rows];
    };
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
          matrix[i][j]=0;
    };
};
};



int main(){

Matrix AA(2,2);

cout << AA[0][0];

return 0;
}

