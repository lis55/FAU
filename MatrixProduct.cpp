
#include <iostream>
#include <typeinfo>
#include "Matrix.h"
#include <assert.h>
using namespace std;

int main(){

size_t s1,s2,s3;

cin>>s1;
cin>>s2;
cin>>s3;

if (typeid(s1) != typeid(size_t()) || typeid(s2) != typeid(size_t()) || typeid(s3) != typeid(size_t())){
cout<<"invalid type"<<endl;
assert(0);
}

Matrix m1(s1,s2,0),m2(s2,s3,0),m3(s1,s3,0);

cin>>m1;
cin>>m2;
cin>>m3;

cout<<m1*m2<<endl;

return 0;
}
