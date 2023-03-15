#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct Score
{
	string name;
	int c = 0, m = 0, e = 0, a = 0;
};
int main() {
	int c[101], m[101], e[101], a[101];
	for (int i = 0; i < 101; i++) {
		c[i] = 0;
		m[i] = 0;
		e[i] = 0;
		a[i] = 0;
	}

	int n1, n2;
	cin >> n1 >> n2; 
	Score* s = new Score[n1];
	for (int i = 0; i < n1; i++) {
		cin >> s[i].name;
		scanf("%d %d %d", &s[i].c, &s[i].m, &s[i].e);
		s[i].a = (s[i].c + s[i].m + s[i].e) / 3;
		c[s[i].c]++;
		m[s[i].m]++;
		e[s[i].e]++;
		a[s[i].a]++;
	}
	for (int i = 1; i < 101; i++) {
		c[i] = c[i] + c[i - 1];
		m[i] = m[i] + m[i - 1];
		e[i] = e[i] + e[i - 1];
		a[i] = a[i] + a[i - 1];
	}
	int i = 0;
	for (i = 0; i < n2; i++) {
		string n;
		cin >> n;
		int j;
		for (j = 0; j < n1; j++) {
			if (s[j].name == n) {
				int hc = -1;
				char o = ' ';
				if (a[s[j].a] > hc) {
					hc = a[s[j].a];
					o = 'A';
				}
				if (c[s[j].c] > hc) {
					hc = c[s[j].c];
					o = 'C';
				}
				if (m[s[j].m] > hc) {
					hc = m[s[j].m];
					o = 'M';
				}
				if (e[s[j].e] > hc) {
					hc = e[s[j].e];
					o = 'E';
				}
				printf("%d %c", n1-hc+1, o);
				break;
			}
		}
		if (j == n1) {
			cout << "N/A";
		}
		if (i < n2 - 1) {
			cout << endl;
		}
	}
	return 0;
}