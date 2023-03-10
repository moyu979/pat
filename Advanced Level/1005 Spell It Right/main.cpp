#include<iostream>
#include<queue>
#include<stack>
using namespace std;
string map[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
void output(long long int a) {
    int k = a % 10;
    int n = a / 10;
    
    if (n == 0) {
        cout << map[k];
    }
    else {
        output(n);
        cout << " " << map[k];
    }
}

int main() {
    
    string s;
    cin >> s;
    long long int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += s[i] - '0';
    }
    output(ans);
}