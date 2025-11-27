// Solve 2025-11-27

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

    int n, a, b;
    cin >> n >> a >> b;

    if (n < a + b - 1) {
        cout << -1 << '\n';
        return 0;
    }

    if (a == 1) {
        cout << b << ' ';

        int iter = n - b;
        while (iter-- > 0) cout << 1 << ' ';

        for (int i = b - 1; i >= 1; i--) cout << i << ' ';
        cout << '\n';
        return 0;
    }

    int iter = n - (a + b - 1);
    while (iter-- > 0) cout << 1 << ' ';

    for (int i = 1; i < a; i++) cout << i << ' ';
    cout << max(a, b) << ' ';
    for (int i = b - 1; i >= 1; i--) cout << i << ' ';
    cout << '\n';

    return 0;
}
