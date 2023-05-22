// Solve 2023-05-21

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int cnt[26];
string mobis = "MOBIS";

int main() {
    FASTIO;

    string s;
    cin >> s;

    for (auto &ch : s) {
        cnt[ch - 'A']++;
    }

    string ans = "YES";
    for (auto &ch : mobis) {
        if (cnt[ch - 'A'] == 0) {
            ans = "NO";
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}
