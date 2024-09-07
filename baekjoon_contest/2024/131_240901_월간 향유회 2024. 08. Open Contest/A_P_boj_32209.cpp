// Solve 2024-09-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int q;
    cin >> q;

    bool ans = true;
    int a = 0;

    for (int i = 0; i < q; i++) {
        int cmd, x;
        cin >> cmd >> x;

        if (cmd == 1) {
            a += x;
        }
        else {
            a -= x;

            if (a < 0) {
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "See you next month\n" : "Adios\n");

    return 0;
}
