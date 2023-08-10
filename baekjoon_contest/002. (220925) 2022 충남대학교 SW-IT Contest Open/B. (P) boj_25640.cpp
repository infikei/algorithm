// Solve 2022-09-25
// Update 2023-08-10

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

    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1;
        cin >> s1;

        if (s == s1) ans++;
    }

    cout << ans << '\n';

    return 0;
}
