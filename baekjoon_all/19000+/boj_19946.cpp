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

    ull n;
    cin >> n;
    ull diff = 18446744073709551615 - n + 1;

    for (int i = 0; i < 64; i++) {
        if (diff == (1ULL << i)) {
            cout << 64 - i << '\n';
            return 0;
        }
    }

    return 0;
}
