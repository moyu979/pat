#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Node {
    bool exist = false;
    bool isLeaf = true;
    vector<int> childs;
};

int main() {
    int n, m, l = 0;
    cin >> n;
    Node* nodes = new Node[n + 1];
    if (n <= 0) {
        return 0;
    }
    if (n >= 100) {
        return 0;
    }
    cin >> m;
    nodes[1].exist = true;
    for (int i = 0; i < m; i++) {
        int nodeNum = 0, childs = 0;
        cin >> nodeNum;
        nodes[nodeNum].exist = true;
        cin >> childs;
        for (int j = 0; j < childs; j++) {
            int child;
            cin >> child;
            nodes[child].exist = true;
            nodes[nodeNum].childs.push_back(child);
            nodes[nodeNum].isLeaf = false;
        }
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i + 1].exist) {
            l++;
        }
    }
    queue<int> levels;
    int nowend = 1;
    int count = 0;
    levels.push(1);
    while (!levels.empty()) {
        int n1 = levels.front();
        levels.pop();
        //cout << "visit " << n1<<endl;
        if (nodes[n1].isLeaf) {
            count++;
        }
        else {
            for (int i = 0; i < nodes[n1].childs.size(); i++) {
                int c = nodes[n1].childs[i];
                //cout << "add " << c << endl;
                //cout << "nowend " << nowend << endl;
                levels.push(c);
            }
        }
        if (n1 == nowend) {
            if (nowend != 1) {
                cout << " " << count;
            }
            else {
                cout << count + n - l;
            }
            count = 0;
            nowend = levels.size()==0?0:levels.back();
        }
        
        
    }
    return 0;
}