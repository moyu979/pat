#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main() {
	char output = ' ';
	char m[3] = { 'W','T','L' };
	float rate = 1;
	for (int i = 0; i < 3; i++) {
		float max=0;
		for (int j = 0; j < 3; j++) {
			float r;
			cin >> r;
			if (max < r) {
				output = m[j];
				max = r;
			}
		}
		printf("%c ", output);
		rate = rate * max;
	}
	float o = rate * 1.3 - 2;
	printf("%.2f", o);
	return 0;
}