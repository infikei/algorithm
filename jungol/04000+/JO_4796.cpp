// Solve 2026-06-21

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

    int n, c;
    cin >> n >> c;

    int a = n;
    int b = n;

    for (int i = 0; i < c; i++) {
        int x, y;
        cin >> x >> y;

        if (x >= a || y >= b) continue;

        if (x * b >= a * y) {
            a = x;
        }
        else {
            b = y;
        }
    }

    cout << a * b << '\n';
    return 0;
}
