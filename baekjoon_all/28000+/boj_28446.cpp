// Solve 2023-08-16

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

    unordered_map<int, int> hs;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x, w;
            cin >> x >> w;

            hs[w] = x;
        }
        else {
            int w;
            cin >> w;

            cout << hs[w] << '\n';
        }
    }

    return 0;
}
