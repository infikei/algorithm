// Solve 2025-11-02

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

bool has_interest(int x, int a, int b, int c) {
    if (x >= 3) return false;
    if (c < 50) return false;

    int cut = (x == 1 ? 100 : 90);

    return (3 * a < cut && 3 * b < cut) || a <= 21 || b <= 21;
}

int main() {
    FASTIO;

    int q;
    cin >> q;

    while (q-- > 0) {
        int x, a, b, c;
        cin >> x >> a >> b >> c;

        cout << (has_interest(x, a, b, c) ? "YES" : "NO") << '\n';
    }

    return 0;
}
