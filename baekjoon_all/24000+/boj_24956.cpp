// Solve 2025-10-07

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

ll two_pow[200001];

int main() {
    FASTIO;

    two_pow[0] = 1;

    for (int i = 1; i <= 200000; i++) {
        two_pow[i] = two_pow[i - 1] * 2 % MOD;
    }

    int n;
    string s;
    cin >> n >> s;

    ll w = 0;
    ll h = 0;
    int e = 0;

    for (int i = size(s) - 1; i >= 0; i--) {
        if (s[i] == 'E') {
            e++;
        }
        else if (s[i] == 'H') {
            ll ee = (two_pow[e] - e - 1 + MOD) % MOD;
            h = (h + ee) % MOD;
        }
        else if (s[i] == 'W') {
            w = (w + h) % MOD;
        }
    }

    cout << w << '\n';
    return 0;
}
