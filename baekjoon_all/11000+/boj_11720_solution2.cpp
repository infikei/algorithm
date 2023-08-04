// Solve 2022-06-05
// Update 2023-08-03

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

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += s[i] - '0';
    }

    cout << ans << '\n';

    return 0;
}
