// Solve 2025-11-24

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

    int n, m, a, d, x, y;
    cin >> n >> m >> a >> d >> x >> y;

    if (d == 0) {
        if (x == 1 && y > a) {
            cout << "YES!" << '\n';
        }
        else if (x == n && y != m && n % 2 == 1) {
            cout << "YES!" << '\n';
        }
        else {
            cout << "NO..." << '\n';
        }
    }
    else {
        if (x == 1 && y < a) {
            cout << "YES!" << '\n';
        }
        else if (x == n && y != m && n % 2 == 0) {
            cout << "YES!" << '\n';
        }
        else {
            cout << "NO..." << '\n';
        }
    }

    return 0;
}
