// Solve 2022-09-06
// Update 2023-08-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int m;
    cin >> m;

    int st = 0;

    for (int i = 0; i < m; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;

            st |= 1 << x;
        }
        else if (cmd == "remove") {
            int x;
            cin >> x;

            st &= ~(1 << x);
        }
        else if (cmd == "check") {
            int x;
            cin >> x;

            if (st & (1 << x)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "toggle") {
            int x;
            cin >> x;

            st ^= 1 << x;
        }
        else if (cmd == "all") {
            st = 2097151;
        }
        else {
            st = 0;
        }
    }

    return 0;
}
