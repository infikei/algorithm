// Solve 2022-08-12
// Update 2023-12-19

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

    int ans = 0;
    int layer = 0;

    for (int i = 0, i_end = SIZE(s); i < i_end; i++) {
        if (s[i] == '(' && s[i + 1] == ')') {
            ans += layer;
            i++;
        }
        else if (s[i] == '(') {
            layer++;
            ans++;
        }
        else {
            layer--;
        }
    }

    cout << ans << '\n';

    return 0;
}
