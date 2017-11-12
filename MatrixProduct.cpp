
#include <iostream>
#include "Matrix.h"
#include <assert.h>
#include <fstream>
using namespace std;

int main(){
ifstream in("BigMatrix.input.txt",ios::in);
size_t s1,s2,s3;
Matrix m1(s1,s2,0),m2(s2,s3,0),m3(s1,s3,0);

cin>>s1>>s2>>s3>>m1>>m2;

if ((s1==0) || (s2==0) || (s3==0)){
	cout << "None of the sizes can be 0" << endl;
	return 1;}
else if((s1<0) || (s2<0) || (s3<0)){	
	cout << "None of the sizes can be negative" << endl;}

m3=m1*m2;

cout<<m3<<endl;

return 0;
}
