#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct Node {
    int value=0;
    int nexti=-1;
};

int main() {
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> list;
    Node* node = new Node[100001];
    int n, start;
    cin >> n >>start;
    
    if (n == 0) {
        cout << "0 -1";
        return 0;
    }
    //cin >> start;
    for (int i = 0; i < n; i++) {
        int add;
        cin >> add;
        cin >> node[add].value;
        cin >> node[add].nexti;
    }

    while (start != -1) {
        list.push(make_pair(node[start].value, start));
        start = node[start].nexti;
    }
    if (list.size()) {
        cout << list.size() << " " ;
        printf("%05d\n", list.top().second);
        while (list.size() != 1) {
            printf("%05d %d ", list.top().second,list.top().first);
            list.pop();
            printf("%05d\n", list.top().second);
        }
        printf("%05d %d -1", list.top().second, list.top().first);
    }
    else {
        cout << "0 -1";
    }
    
    
    

    return 0;
}