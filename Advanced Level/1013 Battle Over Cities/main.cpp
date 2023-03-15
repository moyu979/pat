#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
void dfs(bool* v, bool** p, int n,int node) {
	v[node] = true;
	//cout << "visit " << node << endl;
	for (int i = 1; i < n+1; i++) {
		if (v[i] == false && p[i][node]) {
			dfs(v, p, n, i);
		}
	}
}
int main() {
	int* ways;
	bool* visited;
	bool** path;
	bool* t;
	int n, m, k;
	cin >> n >> m >> k;
	visited = new bool[n + 1];
	t = new bool[n + 1];
	path = new bool* [n + 1];
	ways = new int[k];
	for (int i = 0; i < n + 1; i++) {
		visited[i] = false;
		t[i] = false;
		path[i] = new bool[n + 1];
		for (int j = 0; j < n + 1; j++) {
			path[i][j] = false;
		}
	}
	for (int i = 0; i < m; i++) {
		int s, d;
		cin >> s >> d;
		path[s][d] = true;
		path[d][s] = true;
	}
	for (int i = 0; i < k; i++) {
		//cout << endl;
		ways[i] = 0;
		int s;
		cin >> s;
		visited[s] = true;
		for (int j = 0; j < n + 1; j++) {
			t[j] = path[s][j];
			path[s][j] = false;
			path[j][s] = false;
		}
		int j = 1;
		while (j<n+1)
		{
			if(visited[j]==false){
				//cout << "start " << j << endl;
				dfs(visited, path, n, j);
				ways[i]++;
			}
			j++;
		}

		for (int j = 0; j < n + 1; j++) {
			visited[j] = false;
			path[s][j] = t[j];
			path[j][s] = t[j];
			t[j] = false;
		}
		
	}
	for (int i = 0; i < k; i++) {
		cout << ways[i]-1 << (i == k - 1 ? "" : "\n");
	}
	return 0;
}