// Solve 2023-12-21
// Update 2025-09-10

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

    int a, b;
    cin >> a >> b;

    int d = a * a - b;

    if (d >= 0) {
        int sqrt_d = sqrt(d);

        if (sqrt_d * sqrt_d == d) {
            int x1 = -a - sqrt_d;
            int x2 = -a + sqrt_d;

            if (x1 > x2) swap(x1, x2);

            cout << x1 << ' ';

            if (x1 != x2) {
                cout << x2 << ' ';
            }
        }
    }

    cout << '\n';
    return 0;
}
