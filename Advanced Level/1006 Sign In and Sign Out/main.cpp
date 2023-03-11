#include<iostream>
#include<queue>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

int main() {
    int number;
    cin >> number;
    priority_queue<pair<string, string>, vector<pair<string, string>>, greater<pair<string, string>>> early;
    priority_queue<pair<string, string>> late;
    for (int i = 0; i < number; i++) {
        string usr, login, logout;
        cin >> usr >> login >> logout;
        early.push(make_pair(login, usr));
        late.push(make_pair(logout, usr));
    }
    cout << early.top().second << " " << late.top().second;
    return 0;
}