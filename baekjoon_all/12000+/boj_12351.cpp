// Solve 2025-12-31

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

double h[10];

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        for (int i = 1; i < n - 1; i++) {
            h[i] = min(h[i], (h[i - 1] + h[i + 1]) * 0.5);
        }

        SETP(9);
        cout << "Case #" << ti << ": " << h[n - 2] << '\n';
    }

    return 0;
}
