// Solve 2026-02-05

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

    while (n-- > 0) {
        int x;
        char c;
        cin >> x >> c;

        int d = (c == '!' ? 10 : c - '0');

        while (x-- > 0) {
            cin >> c;
            cin >> c;
            d += (c == '!' ? 10 : c - '0');
        }

        cout << (d >= 10 ? '!' : (char) ('0' + d)) << '\n';
    }

    return 0;
}
