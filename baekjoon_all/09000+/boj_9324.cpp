// Solve 2023-11-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string s;
        cin >> s;

        vector<int> cnt(91, 0);
        bool ans = true;

        for (int i = 0, ie = SIZE(s); i < ie; i++) {
            if (++cnt[s[i]] == 3) {
                cnt[s[i]] = 0;

                if (++i >= ie || s[i] != s[i - 1]) {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) cout << "OK\n";
        else cout << "FAKE\n";
    }

    return 0;
}
