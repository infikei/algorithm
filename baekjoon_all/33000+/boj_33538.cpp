// Solve 2025-12-05

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

    int l, n;
    double t;
    cin >> l >> n >> t;

    while (n-- > 0) {
        double f, b;
        cin >> f >> b;
        double cur_t = l / f + l / b;

        if (cur_t < t) {
            cout << "HOPE" << '\n';
            return 0;
        }
    }

    cout << "DOOMED" << '\n';
    return 0;
}
