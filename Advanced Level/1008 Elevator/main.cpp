#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#pragma warning(disable:4996)
using namespace std;

int main() {
    int number = 0;
    cin >> number;
    int second = 0;
    int start = 0;
    for (int i = 0; i < number; i++) {
        int dest;
        cin >> dest;
        while (start != dest) {
            if (start < dest) {
                start++;
                second += 6;
            }
            else {
                start--;
                second += 4;
            }
            
        }
        second += 5;
    }
    cout << second;
    return 0;
}