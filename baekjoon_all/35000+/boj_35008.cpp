// Solve 2025-12-26

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

int n;
int a[7];
ll mn = LLINF;
ll mx = 0;

void recur(int depth, int garo, int sero) {
    if (depth == n) {
        if (garo == 0 || sero == 0) return;

        ll area = (ll) garo * sero;
        mn = min(mn, area);
        mx = max(mx, area);
        return;
    }

    recur(depth + 1, garo, sero + a[depth]);
    recur(depth + 1, garo + a[depth], sero);
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    recur(0, 0, 0);
    cout << mn << ' ' << mx << '\n';
    return 0;
}
