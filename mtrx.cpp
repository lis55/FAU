#include<iostream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(){
matrix=NULL;
}

Matrix::Matrix(int x, int y){
    rows=x;
    columns=y;
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

istream& operator>>(istream& stream, Matrix& m){

for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            stream >> m.matrix[i * m.columns + j];
        }
}

return (stream);

}

bool Matrix::operator==(const Matrix& m) const
{
    for (int i=0;i<m.rows*m.columns;i++){
        if(this->matrix[i]!=m.matrix[i])
        return(false);
    }
    return(true);
}

bool Matrix::operator!=(const Matrix& m) const
{
    for (int i=0;i<m.rows*m.columns;i++){
        if(this->matrix[i]==m.matrix[i])
        return(false);
    }
    return(true);
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
Matrix sum(this->rows,this->columns);
for(int i = 0; i < this->rows*this->columns; i++){
    sum.matrix[i]=this->matrix[i]+m.matrix[i];
}
return(sum);
}

Matrix Matrix::operator-(const Matrix& m) const{
Matrix sum(this->rows,this->columns);
for(int i = 0; i < this->rows*this->columns; i++)
    sum.matrix[i]=this->matrix[i]-m.matrix[i];
return sum;
}


Matrix Matrix::operator*(const Matrix& m) const{
Matrix sum(this->rows,m.columns);
    for(int i = 0; i < sum.rows; i++)
        for(int j = 0; j < sum.columns; j++)
            for (int k=0; k< this->columns; k++)
                sum.matrix[i * sum.columns + j] += (this->matrix[i * this->columns + k] * m.matrix[k * m.columns + j]);
return sum;
}

Matrix& Matrix::operator*=(const Matrix& m){
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < m.columns; j++)
            for (int k=0; k<this->rows; k++)
                this->matrix[i * this->columns + j] += (this->matrix[i * this->columns + k] * m.matrix[k * m.columns + j]);
return *this;
}

Matrix& Matrix::operator-=(const Matrix& m){

for(int i = 0; i < m.rows*m.columns; i++){
    this->matrix[i]-=m.matrix[i];
}
return(*this);

}

Matrix& Matrix::operator+=(const Matrix& m){

for(int i = 0; i < m.rows*m.columns; i++){
    this->matrix[i]+=m.matrix[i];
}
return(*this);
}

int main(){

Matrix A(2,2),B(1,2), C(2,1);
cin >>A;
cin>>C;


cout<<A<<endl<<C<<endl<< A*C <<endl<<B*A<<endl;

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
