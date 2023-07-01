// Solve 2022-08-12
// Update 2023-07-01

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

    int ans = 0, now = 0;
    for (int i = 0, i_end = SIZE(s); i < i_end; i++) {
        if (s[i] == '(') {
            if (s[i + 1] == ')') {
                ans += now;
            }
            else {
                now++;
            }
        }
        else {
            if (s[i - 1] == '(') {
                continue;
            }
            else {
                now--;
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
