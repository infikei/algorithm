// Solve 2025-10-15

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

ll n;
ll ans = 0;
bool selected[10];

void recur(int depth, ll val) {
    if (abs(n - val) < abs(n - ans)) {
        ans = val;
    }
    else if (abs(n - val) == abs(n - ans) && val < ans) {
        ans = val;
    }

    if (depth == 10) return;

    for (int d = 0; d < 10; d++) {
        if (selected[d]) continue;

        selected[d] = true;
        recur(depth + 1, val * 10 + d);
        selected[d] = false;
    }
}

int main() {
    FASTIO;

    cin >> n;

    if (n >= 9876543210LL) {
        cout << 9876543210LL << '\n';
        return 0;
    }

    recur(0, 0);
    cout << ans << '\n';
    return 0;
}
