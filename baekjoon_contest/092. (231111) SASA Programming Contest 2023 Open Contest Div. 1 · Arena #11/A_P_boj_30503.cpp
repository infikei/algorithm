// Solve 2023-11-11
// Update 2023-12-25

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

    int a[1001];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int qi = 0; qi < q; qi++) {
        int cmd, l, r;
        cin >> cmd >> l >> r;

        if (cmd == 1) {
            int k;
            cin >> k;

            int ans = 0;

            for (int i = l; i <= r; i++) {
                if (a[i] == k) {
                    ans++;
                }
            }

            cout << ans << '\n';
        }
        else {
            for (int i = l; i <= r; i++) {
                a[i] = 0;
            }
        }
    }

    return 0;
}
