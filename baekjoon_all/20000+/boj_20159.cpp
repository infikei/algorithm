// Solve 2025-12-10

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

int prefix[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
    }

    for (int i = 3; i <= n; i++) {
        prefix[i] += prefix[i - 2];
    }

    int mx = max(prefix[n - 1], prefix[n]);

    for (int i = 1; i <= n - 3; i += 2) {
        mx = max(mx, prefix[i] + prefix[n - 2] - prefix[i - 1]);
        mx = max(mx, prefix[i] + prefix[n] - prefix[i + 1]);
    }

    cout << mx << '\n';
    return 0;
}
