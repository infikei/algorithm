// Solve 2025-12-11

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

ll div_ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    FASTIO;

    ll n, k;
    cin >> n >> k;

    ll left = k * (k + 1) / 2;
    ll right = k * (2 * n - k + 1) / 2;

    left = div_ceil(left, k + 1) * (k + 1);
    right = right / (k + 1) * (k + 1);

    cout << (left <= right ? "YES" : "NO") << '\n';
    return 0;
}
