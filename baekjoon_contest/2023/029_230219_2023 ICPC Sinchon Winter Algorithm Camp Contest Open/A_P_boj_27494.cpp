// Solve 2023-02-19
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

    int ans = 0;
    string s = "2023";

    for (int k = 2023; k <= n; k++) {
        int state = 0;

        for (char &c : to_string(k)) {
            if (c == s[state]) {
                if (++state == 4) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
