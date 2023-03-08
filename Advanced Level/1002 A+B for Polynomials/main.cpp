#include<iostream>
using namespace std;
int main() {
	float pars[2001];
	int nums;
	cin >> nums;
	for (int i = 0; i < 2001; i++) {
		pars[i] = 0;
	}
	for (int i = 0; i < nums; i++) {
		float b;
		int a;
		cin >> a >> b;
		pars[a] += b;
	}

	cin >> nums;
	for (int i = 0; i < nums; i++) {
		float b;
		int a;
		cin >> a >> b;
		pars[a] += b;
	}
	nums = 0;
	for (int i = 0; i < 2001; i++) {
		if (pars[i] != 0) {
			nums++;
		}
	}
	cout << nums;
	if (nums != 0) {
		cout << " ";
	}
	for (int i = 2000; i > -1; i--) {
		if (pars[i] != 0) {
			nums--;
			printf("%d %.1f", i, pars[i]);
			cout << (nums == 0 ? "" : " ");
		}
	}
	//cout << endl;
	return 0;
}