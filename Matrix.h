#include<iostream>
#include <assert.h>
using namespace std;

class Matrix{
    private:
    //int rows_, cols_;
    //size_t rows_, cols_;
    //double *matrix;
    public:
   size_t rows_, cols_;
   double *matrix;
    Matrix();
    Matrix(size_t,size_t, double);
    ~Matrix();
    Matrix(const Matrix &m);
    size_t rows() const;
    size_t cols() const;
    //int setvalues();
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;
    Matrix& operator=( const Matrix &m);
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;
    Matrix& operator+=(const Matrix& m);
    Matrix& operator-=(const Matrix& m);
    Matrix& operator*=(const Matrix& m);
double& operator()(size_t,size_t);
const double& operator()(size_t i, size_t j) const;
    friend ostream& operator<<(ostream& stream,const Matrix& m);
    friend istream& operator>>(istream& stream, Matrix& m);
};
ostream& operator<<(ostream& stream,const Matrix& m);
istream& operator>>(istream& stream, Matrix& m);

Matrix::Matrix(){
matrix=NULL;
}

double& Matrix::operator()(size_t i,size_t j){

         if( i > rows_ || j>cols_ ) {
            cout << "Index out of bounds" <<endl;
            // return first element.
            return matrix[0];
         }

         return matrix[i * cols_ + j];}
const double& Matrix::operator()(size_t i, size_t j) const{

         if( i > rows_ || j>cols_ ) {
            cout << "Index out of bounds" <<endl;
            // return first element.
            return matrix[0];
         }

         return matrix[i * cols_ + j];}

Matrix::Matrix(size_t x, size_t y, double z){
    rows_=x;
    cols_=y;
    matrix = new double[rows_*cols_];
    for(size_t i = 0; i < rows_*cols_; ++i){
            matrix[i]=z;
    }
}

Matrix::~Matrix(){
    delete [] matrix;
}

size_t Matrix::rows() const{
return(rows_);
}

size_t Matrix::cols() const{
return(cols_);
}


ostream& operator<<(ostream& stream, const Matrix& m){

for(size_t i = 0; i < m.rows_; i++){
        for(size_t j = 0; j < m.cols_; j++){
            stream <<  m.matrix[i * m.cols_ + j] << "\t";
        }

        stream << endl;
}
return (stream);
}

istream& operator>>(istream& stream, Matrix& m){

for(size_t i = 0; i < m.rows_; i++){
        for(size_t j = 0; j < m.cols_; j++){
            stream >> m.matrix[i * m.cols_ + j];
        }
}

return (stream);

}

bool Matrix::operator==(const Matrix& m) const
{
    for (size_t i=0;i<m.rows_*m.cols_;i++){
        if(this->matrix[i]!=m.matrix[i])
        return(false);
    }
    return(true);
}

bool Matrix::operator!=(const Matrix& m) const
{
    if (this->rows_!=m.rows_ || this->cols_!=m.cols_){
        return true;
    }
    for (size_t i=0;i<m.rows_*m.cols_;i++){
        if(this->matrix[i]==m.matrix[i])
        return(false);
    }
    return(true);
}

Matrix& Matrix::operator=(const Matrix &m) {
    if (rows_ * cols_ != m.rows_ * m.cols_) {
        delete [] this->matrix;
        this->matrix = new double[m.rows_ * m.cols_];
    }
    rows_ = m.rows_;
    cols_ = m.cols_;
    //for (size_t r = 0; r < rows_; r++) {
       //for (size_t c = 0; c < cols_; c++) {
    for (size_t r = 0; r < rows_; r++) {
       for (size_t c = 0; c < cols_; c++) {
          this->matrix[r * cols_ + c] = m.matrix[r * cols_ + c];
       }
    }
    return *this;
}

Matrix::Matrix(const Matrix &m):   rows_    (m.rows_),
                                   cols_ (m.cols_),
                                   matrix  (new double[rows_* cols_])
{
    for(size_t i = 0; i < rows_; i++)
        for(size_t j = 0; j < cols_; j++)
            matrix[i * cols_ + j] =  m.matrix[i * cols_ + j];

}

Matrix Matrix::operator+(const Matrix& m) const{
assert(this->rows_==m.rows_);
assert(this->cols_==m.cols_);
Matrix sum(this->rows_,this->cols_,0.0);
for(size_t i = 0; i < this->rows_*this->cols_; i++){
    sum.matrix[i]=this->matrix[i]+m.matrix[i];
}
return(sum);
}

Matrix Matrix::operator-(const Matrix& m) const{
assert(this->rows_==m.rows_);
assert(this->cols_==m.cols_);
Matrix sum(this->rows_,this->cols_,0.0);
for(size_t i = 0; i < this->rows_*this->cols_; i++)
    sum.matrix[i]=this->matrix[i]-m.matrix[i];
return sum;
}


Matrix Matrix::operator*(const Matrix& m) const{
assert(this->cols_==m.rows_);
Matrix sum(this->rows_,m.cols_,0.0);
    for(size_t i = 0; i < sum.rows_; i++)
        for(size_t j = 0; j < sum.cols_; j++)
            for (size_t k=0; k< this->cols_; k++)
                sum.matrix[i * sum.cols_ + j] += (this->matrix[i * this->cols_ + k] * m.matrix[k * m.cols_ + j]);
return sum;
}

Matrix& Matrix::operator*=(const Matrix& m){
    for(size_t i = 0; i < this->rows_; i++)
        for(size_t j = 0; j < this->cols_; j++)
            for (size_t k=0; k< this->cols_; k++)
                this->matrix[i * this->cols_ + j] += (this->matrix[i * this->cols_ + k] * m.matrix[k * m.cols_ + j]);
return *this;
}

Matrix& Matrix::operator-=(const Matrix& m){
assert(this->rows_==m.rows_);
assert(this->cols_==m.cols_);

for(size_t i = 0; i < m.rows_*m.cols_; i++){
    this->matrix[i]-=m.matrix[i];
}
return(*this);

}

Matrix& Matrix::operator+=(const Matrix& m){
assert(this->rows_==m.rows_);
assert(this->cols_==m.cols_);

for(size_t i = 0; i < m.rows_*m.cols_; i++){
    this->matrix[i]+=m.matrix[i];
}
return(*this);
}


