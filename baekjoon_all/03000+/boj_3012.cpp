// Solve 2025-11-21

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
const ll MOD = 100000;

ll memo[200][200];
ll memo2[200];
string pars[9] = {
    "()",
    "(?",
    "?)",
    "{}",
    "{?",
    "?}",
    "[]",
    "[?",
    "?]"
};

int get_score(char c1, char c2) {
    if (c1 == '?' && c2 == '?') {
        return 3;
    }

    for (string& p : pars) {
        if (c1 == p[0] && c2 == p[1]) {
            return 1;
        }
    }

    return 0;
}

ll count(int a, int b) {
    for (int i = a + 1; i <= b; i += 2) {
        memo2[i] = memo[a][i];

        for (int j = a + 1; j < i; j += 2) {
            memo2[i] += memo2[j] * memo[j + 1][i];
        }

        memo2[i] = memo2[i] % MOD + (memo2[i] >= MOD ? MOD : 0);
    }

    return memo2[b];
}

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    if (n % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i < n; i++) {
        memo[i - 1][i] = get_score(s[i - 1], s[i]);
    }

    for (int len = 4; len <= n; len += 2) {
        for (int i = 0, j = i + len - 1; j < n; i++, j++) {
            int val = get_score(s[i], s[j]);

            if (val) {
                memo[i][j] = val * count(i + 1, j - 1);
                memo[i][j] = memo[i][j] % MOD + (memo[i][j] >= MOD ? MOD : 0);
            }
        }
    }

    ll ans = count(0, n - 1);

    if (ans >= MOD) {
        SETW(5, '0');
        cout << ans % MOD << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}
