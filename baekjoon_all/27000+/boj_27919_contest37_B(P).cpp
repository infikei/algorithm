// Solve 2023-03-26

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

int main() {
    FASTIO;

    string v;
    cin >> v;

    int cnt[2] = { 0 };
    for (auto ch : v) {
        if (ch == 'U' || ch == 'C') {
            cnt[0]++;
        }
        else {
            cnt[1]++;
        }
    }

    string ans;
    if (cnt[0] > (cnt[1] + 1) / 2) {
        ans = "U";
    }
    if (cnt[1] > 0) {
        ans += "DP";
    }
    if (SIZE(ans) == 0) {
        ans = "C";
    }
    cout << ans << '\n';

    return 0;
}
