// Solve 2025-11-20

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

int main() {
    FASTIO;

    int a, b, c;
    cin >> a >> b >> c;

    for (int x = 1; x <= a; x++) {
        if (a * (a * a - b * b - c * c - x * x) - 2 * b * c * x == 0) {
            cout << x << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
