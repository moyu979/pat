#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main() {
	int cityNumber, roadNumber, startCity, endCity;
	cin >> cityNumber >> roadNumber >> startCity >> endCity;
	int* teams = new int[cityNumber];
	int* distance = new int[cityNumber];
	bool* visit = new bool[cityNumber];
	int* kind = new int[cityNumber];
	int** PathTable = new int* [cityNumber];
	int team = 0;
	for (int i = 0; i < cityNumber; i++) {
		PathTable[i] = new int[cityNumber];
		for (int j = 0; j < cityNumber; j++) {
			if (j == i) {
				PathTable[i][j] = 0;
			}
			else {
				PathTable[i][j] = INT16_MAX;
			}
		}
		kind[i] = 1;
	}

	for (int i = 0; i < cityNumber; i++) {
		cin >> teams[i];
	}
	for (int i = 0; i < cityNumber; i++) {
		cout << teams[i] << "\t";
	}
	cout << endl;
	
	
	for (int i = 0; i < roadNumber; i++) {
		int start, end, leng;
		cin >> start >> end >> leng;
		PathTable[start][end] = leng;
		PathTable[end][start] = leng;
	}
	for (int i = 0; i < cityNumber; i++) {
		distance[i] =  PathTable[startCity][i];
		visit[i] = false;
	}
	distance[startCity] = 0;
	visit[startCity] = true;
	//——————————————————————————以上为初始化过程————————————————————————————

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> smallHeap;
	
	bool change = true;

	while (!visit[endCity]) {
		change = false;
		for (int i = 0; i < cityNumber; i++) {
			for (int j = 0; j < cityNumber; j++) {
				if (visit[i] && !visit[j] && PathTable[i][j] != INT16_MAX) {
					smallHeap.push(make_pair(PathTable[i][j],make_pair(i, j)));
					cout << "push (" << i << "," << j << endl;
				}
			}
		}
		
		/*if (smallHeap.empty()) {
			break;
		}*/
		pair<int, int> p = smallHeap.top().second;
		cout << "pop (" << p.first << "," << p.second << endl;
		cout << "add team " << teams[p.first] << " in " << p.first << " to " << p.second << endl;

		teams[p.second] += teams[p.first];
		teams[p.first] = 0;
		while (!smallHeap.empty()) {
			smallHeap.pop();
		}
		distance[p.second] = distance[p.first] + PathTable[p.first][p.second];
		visit[p.second] = true;
		for (int i = 0; i < cityNumber; i++) {
			if (distance[i] > distance[p.second] + PathTable[i][p.second]) {
				distance[i] = distance[p.second] + PathTable[i][p.second];
				change = true;
				cout << "change " << i << endl;
				
			}
			if (distance[i] == distance[p.second] + PathTable[i][p.second] && i!=p.second) {
				cout << "add team " << teams[p.second] << " in " << p.second << " to " << i << endl;
				teams[i] += teams[p.second];
				kind[i] += kind[p.second];
				teams[p.second] = 0;
				change = true;
			}
		}
		cout << "-----------------" << endl;
	}
	cout << distance[endCity] << " " << teams[endCity] << " " << kind[endCity];
	return 0;
}

