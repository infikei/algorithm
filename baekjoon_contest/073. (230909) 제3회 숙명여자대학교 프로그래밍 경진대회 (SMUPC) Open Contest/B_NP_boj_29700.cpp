// Solve 2023-09-11
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int cnt = 0;

        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                cnt = 0;
            }
            else {
                if (++cnt >= k) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
