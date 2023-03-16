#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	int* fTime = new int[k+1];
	int* custom = new int[k + 1];
	queue<int> waiting, query;
	int time = 0;
	//等待时间，顾客号
	queue<pair<int,int>>* aWindow = new queue<pair<int,int>>[n];
	for (int i = 0; i < k; i++) {
		int w;
		cin >> w;
		custom[i+1] = w;
		waiting.push(w);
	}
	//cout << "--------------------" << endl;
	//cout << waiting.size() << endl;
	for (int i = 0; i < q; i++) {
		int w;
		cin >> w;
		//cout << w << endl;
		query.push(w);
	}
	int count = 1;
	for (int i = 0; i < m; i++) {
		if (!waiting.empty()) {
			for (int j = 0; j < n; j++) {
				if (!waiting.empty()) {
					int c = waiting.front();
					waiting.pop();
					aWindow[j].push(make_pair(c, count));
					
					count++;
				}
			}
		}
	}
	//cout << "--------------------" << endl;
	//cout << waiting.size() << endl;
	while (!waiting.empty()) {
		//cout << "--------------------" << endl;
		int small = INT_MAX;
		int p;
		for (int i = 0; i < n; i++) {
			if (!aWindow[i].empty()) {
				if (small > aWindow[i].front().first) {
					small = aWindow[i].front().first;
					p = i;
				}
			}
		}
		//找到最小的之后,经过了这么多分钟
		time += small;
		for (int i = 0; i < n; i++) {
			if (!aWindow[i].empty()) {
				//cout << aWindow[i].front().first;
				aWindow[i].front().first -= small;	
				//cout << ":" << aWindow[i].front().first << endl;
			}
		}
		fTime[aWindow[p].front().second] = time;
		aWindow[p].pop();
		
		aWindow[p].push(make_pair(waiting.front(), count));
		count++;
		//cout << "add " << waiting.front() << " to " << p << endl;
		waiting.pop();
	}
	while (true) {
		bool all = true;
		for (int i = 0; i < n; i++) {
			if (aWindow[i].size()) {
				all = false;
				break;
			}
		}
		if (all) {
			break;
		}
		int small = INT_MAX;
		int p;
		for (int i = 0; i < n; i++) {
			if (!aWindow[i].empty()) {
				if (small > aWindow[i].front().first) {
					small = aWindow[i].front().first;
					p = i;
				}
			}
		}
		//找到最小的之后,经过了这么多分钟
		time += small;
		for (int i = 0; i < n; i++) {
			if (!aWindow[i].empty()) {
				aWindow[i].front().first -= small;
			}
		}
		fTime[aWindow[p].front().second] = time;
		aWindow[p].pop();
	}
	while (query.size()) {
		int min = fTime[query.front()];
		int st = min - custom[query.front()];
		query.pop();
		int hh = st / 60 + 8;
		int mm = st % 60;
		if (hh >=17) {
			cout << "Sorry";
		}
		else {
			int hour = min / 60;
			int minute = min % 60;
			hour = hour + 8;
			printf("%02d:%02d", hour, minute);
		}
		if (query.size() != 0) {
			cout << endl;
		}
	}
	return 0;
}