#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#pragma warning(disable:4996)
using namespace std;

int main() {
    int n1;
    float mi[2001];

    for (int i = 0; i < 2001; i++) {
        mi[i] = 0;
    }
    vector<pair<int, float>> v1, v2;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int n;
        float a;
        cin >> n >> a;
        v1.push_back(make_pair(n, a));
    }
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int n;
        float a;
        cin >> n >> a;
        v2.push_back(make_pair(n, a));
    }

    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            mi[v1[i].first + v2[j].first] += (v1[i].second * v2[j].second);
        }
    }
    int count=0;
    for (int i = 0; i < 2001; i++) {
        if (mi[i] != 0) {
            count++;
        }
    }
    cout << count;
    for (int i = 2000; i >-1; i--) {
        if (mi[i] != 0) {
            cout << " " << i << " " << fixed << setprecision(1) << mi[i];
        }
    }
    return 0;
}