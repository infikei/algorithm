// Solve 2023-12-23

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
    string s1, s2;
    cin >> n >> s1 >> s2;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int diff = abs(s1[i] - s2[i]);
        diff = min(diff, 26 - diff);
        ans += diff;
    }

    cout << ans << '\n';

    return 0;
}
