#include<iostream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(){
matrix=NULL;
}

Matrix::Matrix(int x, int y){
    rows=y;
    columns=x;
    matrix = new double[rows*columns];
    for(int i = 0; i < rows*columns; ++i){
            matrix[i]=0;
    }
}

Matrix::~Matrix(){
    delete [] matrix;
}

Matrix::getrows(){
return(rows);
}

Matrix::getcolumns(){
return(columns);
}

Matrix::setvalues(){
double a;
for(int i=0;i<rows*columns;i++){
        cin >> a;
        matrix[i]=a;
}
}

ostream& operator<<(ostream& stream, const Matrix& m){

for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            stream <<  m.matrix[i * m.columns + j] << "\t";
        }

        stream << endl;
}
return (stream);

}

istream& operator>>(ostream& stream, const Matrix& m){

for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            stream <<  m.matrix[i * m.columns + j] << "\t";
        }

        stream << endl;
}
return (stream);

}


bool Matrix::operator==(const Matrix& m) const
{
    for (int i=0;i<m.rows*m.columns;i++){

    }
    return(this->matrix==m.matrix);
}

bool Matrix::operator!=(const Matrix& m) const
{
    return(matrix!=m.matrix);
}

Matrix& Matrix::operator=(const Matrix &m) {
    if (rows * columns != m.rows * m.columns) {
        delete [] this->matrix;
        this->matrix = new double[m.rows * m.columns];
    }
    rows = m.rows;
    columns = m.columns;
    for (size_t r = 0; r < rows; r++) {
       for (size_t c = 0; c < columns; c++) {
          this->matrix[r * columns + c] = m.matrix[r * columns + c];
       }
    }
    return *this;
}

Matrix::Matrix(const Matrix &m):   rows    (m.rows),
                                   columns (m.columns),
                                   matrix  (new double[rows* columns])
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            matrix[i * columns + j] =  m.matrix[i * columns + j];

}

Matrix Matrix::operator+(const Matrix& m) const{

for(int i = 0; i < m.rows*m.columns; i++){
    this->matrix[i]+=m.matrix[i];
}
return(*this);

}

Matrix Matrix::operator-(const Matrix& m) const{
for(int i = 0; i < m.rows*m.columns; i++){
    this->matrix[i]-=m.matrix[i];
}

return(*this);

}

Matrix& Matrix::operator-=(const Matrix& m){

for(int i = 0; i < m.rows*m.columns; i++){
    this->matrix[i]-=m.matrix[i];
}
return(*this);

}

int main(){

Matrix A(2,2),B(2,2), C(2,2);
A.setvalues();
C.setvalues();
B=C;

cout<<A<<endl<<B<<endl<< A+B <<endl<<C;

if (B==C){
    cout<<"yes"<<endl;
}
if (C==B){
    cout<<"yes"<<endl;
}

if (A==C){
    cout <<"yes"<<endl;
}
}
