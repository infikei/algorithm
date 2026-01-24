// Solve 2026-01-18

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

int x[10000];
int y[10000];
int z[10000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    int mn = INF;

    for (int i = 0; i < n; i++) {
        int d_mn1 = INF;
        int d_mn2 = INF;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            int d = abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]);

            if (d <= d_mn1) {
                d_mn2 = d_mn1;
                d_mn1 = d;
            }
            else if (d <= d_mn2) {
                d_mn2 = d;
            }
        }

        mn = min(mn, d_mn1 + d_mn2);
    }

    cout << mn << '\n';
    return 0;
}
