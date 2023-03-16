#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
	bool p[100001];
	vector<int> ps;
	p[0] = false;
	p[1] = false;
	p[2] = true; 
	for (int i = 2; i < 100001; i++) {
		p[i] = true;
	}
	ps.push_back(2);
	for (int i = 3; i < 100001; i++) {
		for (auto a : ps) {
			if (i % a == 0) {
				p[i] = false;
				break;
			}
		}
		if (p[i]) {
			ps.push_back(i);
		}
		//cout << i<<" ";
	}
	/*for (auto a : ps) {
		cout << a << " ";
	}*/
	//cout << "e";
	while (true) {
		int num, radix;
		cin >> num;
		if (num < 0) {
			return 0;
		}
		cin >> radix;
		vector<int> n;
		while (num != 0) {
			int k = num % radix;
			num = num - k;
			num = num / radix;
			n.push_back(k);
		}
		int o = 0, r = 0;
		for (int i = 0; i < n.size(); i++) {
			o *= radix; o += n[i];
			r *= radix; r += n[n.size() - i - 1];
		}
		//cout << "o:" << o << " r:" << r << endl;
		if (p[o] && p[r]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}