//19-41783-3
#include<iostream>
#include<string>
#define max 5
using namespace std;
//User Defined Function 1
int add(int x, int y){
return x+y;
}
//User Defined Function 2
int sub(int x, int y){
return x-y;
}
int main(){
int a=10, b=9, c=0; //Assignment
cout << "Hello";
c = a+b; //Addition
int d, e;
d = c-10; //Subtraction
e = d*5 ; //Multiplication
a = add(b, c);
d = sub(a, 10);
return 0;
}
