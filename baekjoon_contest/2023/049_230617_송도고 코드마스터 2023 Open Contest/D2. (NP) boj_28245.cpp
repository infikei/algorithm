// Solve 2023-06-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll m;
        cin >> m;

        if (m == 1) {
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }

        ll m2 = m;
        int k = 0, cnt = 0;
        int ans[2] = { 0 };

        while (true) {
            if (m2 & 1) {
                if (cnt == 2) {
                    ans[0] = ans[1];
                    ans[1] = k;
                }
                else {
                    ans[cnt] = k;
                    cnt++;
                }
            }
            m2 >>= 1;
            k++;
            if (m2 == 0) break;
        }

        if (cnt == 1) {
            ans[0]--;
            cout << ans[0] << ' ' << ans[0] << '\n';
        }
        else {
            ll a = (1LL << ans[0]) + (1LL << ans[1]);
            ll b = (2LL << ans[0]) + (1LL << ans[1]);
            if (m - a <= b - m) {
                cout << ans[0] << ' ' << ans[1] << '\n';
            }
            else {
                cout << ans[0] + 1 << ' ' << ans[1] << '\n';
            }
        }
    }

    return 0;
}
