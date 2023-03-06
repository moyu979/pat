#include<iostream>
using namespace std;
int main(){
    int num;
    int count=0;
    cin>>num;
    while(num!=1){
        if(num%2==0){
            num=num/2;
        }else{
            num=num*3+1;
            num=num/2;
        }
        count++;
    }
    cout<<count;
    return 0;
}