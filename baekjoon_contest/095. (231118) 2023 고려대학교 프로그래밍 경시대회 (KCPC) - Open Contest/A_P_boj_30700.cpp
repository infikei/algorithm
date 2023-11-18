// Solve 2023-11-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    string korea = "KOREA";
    int korea_pos = 0;
    int ans = 0;

    for (char c : s) {
        if (c == korea[korea_pos]) {
            ans++;

            if (++korea_pos == 5) {
                korea_pos = 0;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
