// Solve 2023-12-14

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

        int digit_sum = 0;

        for (char c : s) {
            digit_sum += c - '0';
        }

        int ans = digit_sum + stoi(s.substr(10, 3)) * 10;

        if (ans >= 10000) {
            ans %= 10000;
        }
        else if (ans < 1000) {
            ans += 1000;
        }

        cout << setfill('0') << setw(4) << ans << '\n';
    }

    return 0;
}
