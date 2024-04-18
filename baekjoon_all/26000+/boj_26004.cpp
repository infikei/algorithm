// Solve 2024-04-17

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

    int alpha_cnt[26] = { 0 };

    for (char c : s) {
        alpha_cnt[c - 'A']++;
    }

    int ans = min({ alpha_cnt[0], alpha_cnt[2], alpha_cnt[7], alpha_cnt[8], alpha_cnt[17] });
    cout << ans << '\n';

    return 0;
}
