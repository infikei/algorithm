// Solve 2026-02-18

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

double x[4];
double y[4];

int main() {
    FASTIO;

    while (cin >> x[0] >> y[0]) {
        for (int i = 1; i <= 3; i++) {
            cin >> x[i] >> y[i];
        }

        SETP(3);

        if (x[0] == x[2] && y[0] == y[2]) {
            cout << x[1] + x[3] - x[0] << ' ' << y[1] + y[3] - y[0] << '\n';
        }
        else if (x[0] == x[3] && y[0] == y[3]) {
            cout << x[1] + x[2] - x[0] << ' ' << y[1] + y[2] - y[0] << '\n';
        }
        else if (x[1] == x[2] && y[1] == y[2]) {
            cout << x[0] + x[3] - x[1] << ' ' << y[0] + y[3] - y[1] << '\n';
        }
        else {
            cout << x[0] + x[2] - x[1] << ' ' << y[0] + y[2] - y[1] << '\n';
        }
    }

    return 0;
}
