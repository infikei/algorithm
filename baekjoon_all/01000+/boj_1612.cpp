// Solve 2026-01-28

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

bool memo[1000000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int v = 0;
    int cnt = 0;

    while (true) {
        v = (v * 10 + 1) % n;
        cnt++;

        if (v == 0) {
            cout << cnt << '\n';
            return 0;
        }

        if (memo[v]) break;

        memo[v] = true;
    }

    cout << -1 << '\n';
    return 0;
}
