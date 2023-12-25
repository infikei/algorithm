// Solve 2023-09-10

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
    cin >> n;

    string s;
    cin >> s;

    int s_cnt[26] = { 0 };

    for (char c : s) {
        s_cnt[c - 'A']++;
    }

    string bs = "BRONZESILVER";

    int bs_cnt[26] = { 0 };

    for (char c : bs) {
        bs_cnt[c - 'A']++;
    }

    int ans = 1e9;

    for (int i = 0; i < 26; i++) {
        if (bs_cnt[i] == 0) continue;

        ans = min(ans, s_cnt[i] / bs_cnt[i]);
    }

    cout << ans << '\n';

    return 0;
}
