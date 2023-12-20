// Solve 2023-12-20

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

    int s = -1, c = -1, l = -1;
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        int si, ci, li;
        cin >> si >> ci >> li;

        if (si > s) {
            s = si; c = ci; l = li;
            ans = i;
        }
        else if (si == s) {
            if (ci < c) {
                s = si; c = ci; l = li;
                ans = i;
            }
            else if (ci == c) {
                if (li < l) {
                    s = si; c = ci; l = li;
                    ans = i;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
