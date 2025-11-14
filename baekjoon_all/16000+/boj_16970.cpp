// Solve 2025-11-11

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

int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
            for (int nx = x; nx <= n; nx++) {
                for (int ny = (nx > x ? 0 : y + 1); ny <= m; ny++) {
                    int dx = nx - x;
                    int dy = abs(ny - y);
                    int gcd = get_gcd(dx, dy);

                    if (gcd + 1 == k) {
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
