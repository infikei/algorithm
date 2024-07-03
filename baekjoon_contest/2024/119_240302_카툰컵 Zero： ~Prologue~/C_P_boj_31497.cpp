// Solve 2024-03-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> names(n);

    for (string &name : names) {
        cin >> name;
    }

    int resp = 0;

    for (string &name : names) {
        cout << "? " << name << endl;
        cin >> resp;

        if (resp == 1) {
            cout << "! " << name << endl;
            break;
        }

        cout << "? " << name << endl;
        cin >> resp;

        if (resp == 1) {
            cout << "! " << name << endl;
            break;
        }
    }

    return 0;
}
