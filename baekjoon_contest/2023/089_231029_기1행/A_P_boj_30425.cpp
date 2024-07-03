// Solve 2023-10-29
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
    string s;
    cin >> n >> s;

    int ans = 1;

    for (int len = 1; len <= n; len++) {
        bool flag = true;

        for (int i = 0; i < n; i++) {
            if (s[i] != s[i % len]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans = (n - 1) / len + 1;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
