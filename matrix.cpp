#include<iostream>

class Matrix{
    int rows, columns;
    double** matrix;
    public:
    Matrix(int,int);
    double setrow();

};

Matrix::Matrix(int x, int y){
    rows=y;
    columns=x;
};

double Matrix::setrow(){
    matrix=new double*[columns];
    for(int i=0;i<rows;i++){
        matrix[i]=new double[rows];
    };
};

int main(){



return 0;
}

