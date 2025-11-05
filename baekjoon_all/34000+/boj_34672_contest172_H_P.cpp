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

bool bin[333340];

int main() {
    FASTIO;

    int q;
    cin >> q;

    while (q-- > 0) {
        int r, c;
        ll k;
        cin >> r >> c >> k;
        k--;

        if (r == 1 || c % 3 != 0) {
            cout << -1 << '\n';
            continue;
        }

        int c3 = c / 3;

        if (c3 < 60 && (1LL << c3) <= k) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 0; i < c3; i++) {
            bin[i] = (k & 1);
            k >>= 1;
        }

        for (int i = c3 - 1; i >= 0; i--) {
            cout << (bin[i] ? "322" : "114");
        }

        cout << '\n';

        for (int i = c3 - 1; i >= 0; i--) {
            cout << (bin[i] ? "332" : "144");
        }

        cout << '\n';
    }

    return 0;
}
