// Solve 2023-08-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

unordered_map<string, int> hs;

int main() {
    FASTIO;

    int n;
    cin >> n;

    char prev = '?', ch_b = '?', ch_e = '?';
    bool flag = false;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "?") {
            ch_b = prev;
            flag = true;
            continue;
        }

        if (flag) {
            flag = false;
            ch_e = s[0];
        }

        hs[s]++;
        prev = s.back();
    }

    int m;
    cin >> m;

    string ans;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (ch_b != '?' && ch_b != s[0]) {
            continue;
        }
        if (ch_e != '?' && ch_e != s.back()) {
            continue;
        }
        if (hs.find(s) != hs.end()) {
            continue;
        }

        ans = s;
    }

    cout << ans << '\n';

    return 0;
}
