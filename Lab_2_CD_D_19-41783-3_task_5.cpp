#include <iostream>
#include <string>
using namespace std;

int main(){
    string in;
    cout<<"Enter Input: ";
    getline(cin,in);
    string s = "";
    for(int i=0; i<in.length(); i++){
        if(in[i]=='+' || in[i]=='-' || in[i]=='*' || in[i]=='/'  || in[i]=='%' || in[i]=='='){
            s+=in[i];
        }
    }
    for(int i=0; i<s.length(); i++){
        cout<<" Operator "<<i+1<<" is : "<<s[i]<<endl;
    }
    return 0;
}
