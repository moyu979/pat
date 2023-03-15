#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

long long int getD(string n1, long long int radix) {
    //cout << "radix:" << radix << endl;

    long long int nn1 = 0;
    for (auto s = n1.begin(); s != n1.end(); s++) {
        nn1 *= radix;
        if (*s <= '9' && *s >= '0') {
            nn1 += (*s - '0');
        }
        else {
            nn1 += (*s - 'a' + 10);
        }
    }

    return nn1;
}

int main2() {

    string n1, n2;
    long long int tag;
    long long int radix;
    cin >> n1 >> n2 >> tag >> radix;
    //cout << n1[0] << endl;
    /*if (radix >= 'a') {
        radix = radix - 'a' + 10;
    }*/

    long long int nn1 = 0;

    if (tag == 2) {
        n1.swap(n2);
    }
    if (n1 == n2) {
        
        if (n1.length() == 1) {
            long long int t = getD(n1, 40) + 1;
            if (radix == 1) {
                cout << 1;
            }
            else {
                cout << (t > 2 ? t : 2);
            }
            
            return 0;
        }
        else {
            cout << radix;
            return 0;
        }
    }
    else if (n1 == "0" || n2 == "0") {
        cout << "Impossible";
        return 0;
    }
    nn1 = getD(n1, radix);

    long long int start = 0, end = nn1+1;
    int t;
    for (int i = 0; i < n2.length(); i++) {
        
        if (n2[i] <= '9' && n2[i] >= '0') {
            t = (n2[i] - '0');
        }
        else {
            t = (n2[i] - 'a' + 10);
        }
        if (start < t) {
            start = t;
        }
    }
    start++;

    while (start <= end) {
        long long int mid = (start + end) / 2;
        long long int mr = getD(n2, mid);

        if (mr > nn1 || mr < 0) {
            end = mid - 1;
        }
        else if (mr < nn1) {
            start = mid + 1;
        }
        else {
            cout << mid;
            return 0;
        }
    }
    cout << "Impossible";
    return 0;
}
int main() {
    main2();
    return 0;
}