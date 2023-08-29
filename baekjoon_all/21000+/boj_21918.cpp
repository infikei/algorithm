// Solve 2022-08-02
// Update 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int bulb[4001] = { 0 };

    for (int i = 1; i <= n; i++) {
        cin >> bulb[i];
    }

    for (int i = 0; i < m; i++) {
        int cmd, b, c;
        cin >> cmd >> b >> c;

        if (cmd == 1) {
            bulb[b] = c;
        }
        else if (cmd == 2) {
            for (int j = b; j <= c; j++) {
                bulb[j] = 1 - bulb[j];
            }
        }
        else if (cmd == 3) {
            for (int j = b; j <= c; j++) {
                bulb[j] = 0;
            }
        }
        else {
            for (int j = b; j <= c; j++) {
                bulb[j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << bulb[i] << ' ';
    }

    cout << '\n';

    return 0;
}
