// Solve 2025-05-20

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    string before = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. ";
    string after = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./ ";
    map<char, char> mp;

    for (int i = 0; i < before.size(); i++) {
        mp[after[i]] = before[i];
    }

    string s;

    while (getline(cin, s)) {
        string ans;

        for (char c : s) {
            ans.push_back(mp[c]);
        }

        cout << ans << '\n';
    }

    return 0;
}
