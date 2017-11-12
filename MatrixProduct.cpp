
#include <iostream>
#include "Matrix.h"
#include <assert.h>
#include <fstream>
using namespace std;

int main(){
size_t s1,s2,s3;
double number;
cin>>s1>>s2>>s3;

Matrix m1,m2,m3;
cin>>m1>>m2>>m3;

if (s1*s2<m1.rows()*m1.cols()){
 cout <<"invalid dimensions"<<endl;
}

if ((s1==0) || (s2==0) || (s3==0)){
	cout << "None of the sizes can be 0" << endl;
	return 1;}
else if((s1<0) || (s2<0) || (s3<0)){	
	cout << "None of the sizes can be negative" << endl;}

m3=m1*m2;

cout<<m3<<endl;

return 0;
}
