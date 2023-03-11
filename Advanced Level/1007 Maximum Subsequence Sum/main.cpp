#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#pragma warning(disable:4996)
using namespace std;

int main() {
    int number;
    cin >> number;
    int* nums = new int[number];
    for (int i = 0; i < number; i++) {
        cin >> nums[i];
    }

    long long int* sums = new long long int[number+1];
    bool allneg = true;
    sums[0] = 0;
    for (int i = 1; i < number+1; i++) {
        sums[i] = sums[i - 1] + nums[i-1];
        if (nums[i - 1] >= 0) {
            allneg = false;
        }
    }


    


    long long int max = LLONG_MIN;
    int i = 0, j = 0, mi, mj;
    while (j < number+1) {
        for (i = 0; i < number + 1; i++) {
            for (j = i + 1; j < number + 1; j++) {
                if (sums[j] - sums[i] > max) {
                    max = sums[j] - sums[i];
                    mi = i;
                    mj = j - 1;
                }
            }
        }
    }
    if (!allneg) {
        cout << max << " " << nums[mi] << " " << nums[mj];
    }
    else {
        cout << 0 << " " << nums[0] << " " << nums[number-1];
    }
    
    return 0;
}