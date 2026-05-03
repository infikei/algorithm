// Solve 2026-05-02

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
const int MOD = 998244353;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int ans = 1;
    int cur = 1;

    for (int i = 1; i < size(s); i++) {
        if (s[i - 1] == s[i]) {
            cur = 0;
        }

        cur++;
        ans = (ans + cur) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
