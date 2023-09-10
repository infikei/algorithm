// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    char cc[10] = { 'P', 'p', 'N', 'n', 'B', 'b', 'R', 'r', 'Q', 'q' };
    int nn[10] = { 1, -1, 3, -3, 3, -3, 5, -5, 9, -9 };

    int ans = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;

            for (int k = 0; k < 10; k++) {
                if (cc[k] == c) {
                    ans += nn[k];
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
