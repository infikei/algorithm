// Solve 2026-02-15

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

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
    }
    else {
        for (int i = 0, ie = n / 2; i < ie; i++) {
            cout << 1 << ' ' << 2 << ' ';
        }

        if (n % 2 == 1) {
            cout << 3 << ' ';
        }

        cout << '\n';
    }

    return 0;
}
