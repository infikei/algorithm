// Solve 2025-11-29

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

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    FASTIO;

    int n, x;
    cin >> n >> x;

    int s = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s += a;
    }

    int ans = ceil(max(n * x - s, 0), 100 - x);
    cout << ans << '\n';
    return 0;
}
