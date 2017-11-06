using namespace std;
class Matrix{
    private:
    int rows, columns;
    double *matrix;
    public:
    //explicit Matrix(const Matrix&);
    Matrix();
    Matrix(int,int);
    ~Matrix();
    Matrix(const Matrix &m);
    getrows();
    int getcolumns();
    int setvalues();
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;
    Matrix& operator=( const Matrix &m);
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix& operator+=(const Matrix& m);
    Matrix& operator-=(const Matrix& m);
    friend ostream& operator<<(ostream& stream,const Matrix& m);
    friend istream& operator>>(istream& stream, Matrix& m);
};
ostream& operator<<(ostream& stream,const Matrix& m);
istream& operator>>(istream& stream, Matrix& m);
