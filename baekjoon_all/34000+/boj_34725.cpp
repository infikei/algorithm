// Solve 2025-11-19

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

    int n, m;
    cin >> n >> m;
    int k = n * m / 4;
    int m2 = m / 2;

    for (int i = 0; i < 2; i++) {
        for (int x = 1; x <= k; x += m2) {
            for (int j = 0; j < 2; j++) {
                for (int y = 0; y < m2; y++) {
                    cout << x + y << ' ';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
