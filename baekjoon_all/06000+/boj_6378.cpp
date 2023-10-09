// Solve 2022-12-06
// Update 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        string s;
        cin >> s;

        if (s == "0") break;

        int ans = 0;

        for (char &c : s) {
            ans += c - '0';
        }

        while (ans > 9) {
            s = to_string(ans);
            ans = 0;

            for (char &c : s) {
                ans += c - '0';
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
