// Solve 2023-12-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int cnt[26] = { 0 };

    int n;
    string s;
    cin >> n >> s;

    for (char &c : s) {
        cnt[c - 'a']++;
    }

    string uospc = "uospc";
    int ans = n;

    for (char &c : uospc) {
        ans = min(ans, cnt[c - 'a']);
    }

    cout << ans << '\n';

    return 0;
}
