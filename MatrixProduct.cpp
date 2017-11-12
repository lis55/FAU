#include <iostream>
#include "Matrix.h"
using namespace std;

int main(){

size_t s1,s2,s3;

cin>>s1;
cin>>s2;
cin>>s3;

Matrix m1(s1,s2,0),m2(s2,s3,0),m3(s1,s3,0);

cin>>m1;
cin>>m2;
cin>>m3;

cout<<m1*m2<<endl;

return 0;
}
