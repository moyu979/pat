#include <iostream>
using namespace std;
void output(long);
int main(){
    long int a,b;
    cin>>a>>b;
    long int c=a+b;
    output(c);
}

void output(long a){
    if(a<0){
        cout<<"-";
        output(-a);
    }else if(a>999){
        output(a/1000);
        int o=a%1000,base=100;
        
        cout<<",";
        while(base>1 && o/base==0){
            cout<<"0";
            base/=10;
        }cout<<o;
    }else{
        cout<<a;
    }
}