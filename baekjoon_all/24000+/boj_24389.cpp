// Solve 2025-06-21

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

int n;

void input() {
    cin >> n;
}

void pro() {
    n = n ^ (-n);
    int ans = 0;

    for (int i = 0; i < 32; i++) {
        if (n & 1) ans++;
        n >>= 1;
    }

    cout << ans << '\n';
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
