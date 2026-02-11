// Solve 2026-02-08

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int get_score(string p) {
    if (size(p) == 2) {
        return p[0] == p[1] ? 2 : 0;
    }

    if (p[0] == p[1] && p[1] == p[2]) {
        return 2;
    }

    if (p[0] == p[1] || p[1] == p[2] || p[2] == p[0]) {
        return 1;
    }

    return 0;
}

int memo[1000];
int nxt[1000];

int main() {
    FASTIO;

    string s;
    cin >> s;
    int n = size(s);

    memo[n - 1] = -INF;
    memo[n - 2] = get_score(s.substr(n - 2, 2));
    nxt[n - 2] = n;

    if (n >= 3) {
        memo[n - 3] = get_score(s.substr(n - 3, 3));
        nxt[n - 3] = n;
    }

    for (int i = n - 4; i >= 0; i--) {
        int m3 = memo[i + 3] + get_score(s.substr(i, 3));
        int m2 = memo[i + 2] + get_score(s.substr(i, 2));

        if (m2 >= m3) {
            memo[i] = m2;
            nxt[i] = i + 2;
        }
        else {
            memo[i] = m3;
            nxt[i] = i + 3;
        }
    }

    int pos = 0;

    while (pos < n) {
        int nxt_pos = nxt[pos];

        while (pos < nxt_pos) {
            cout << s[pos];
            pos++;
        }

        pos = nxt_pos;

        if (pos < n) {
            cout << '-';
        }
    }

    cout << '\n';
    return 0;
}
