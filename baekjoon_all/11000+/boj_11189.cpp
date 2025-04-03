// Solve 2025-04-03

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

    string s;
    cin >> s;

    int u = 0;
    char cur = s[0];

    for (int i = 1; i < s.size(); i++) {
        if (cur != s[i]) {
            u++;
            cur = s[i];
        }

        if (cur != 'U') {
            u++;
            cur = 'U';
        }
    }

    int d = 0;
    cur = s[0];

    for (int i = 1; i < s.size(); i++) {
        if (cur != s[i]) {
            d++;
            cur = s[i];
        }

        if (cur != 'D') {
            d++;
            cur = 'D';
        }
    }

    int ans = 0;
    cur = s[0];

    for (int i = 1; i < s.size(); i++) {
        if (cur != s[i]) {
            ans++;
            cur = s[i];
        }
    }

    cout << u << '\n';
    cout << d << '\n';
    cout << ans << '\n';

    return 0;
}
