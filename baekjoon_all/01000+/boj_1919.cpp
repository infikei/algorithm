// Solve 2022-11-26
// Update 2023-08-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int alphabet_cnt[2][26];

int main() {
    FASTIO;

    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;

        for (const char c : s) {
            alphabet_cnt[i][c - 'a']++;
        }
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        ans += abs(alphabet_cnt[0][i] - alphabet_cnt[1][i]);
    }

    cout << ans << '\n';

    return 0;
}
