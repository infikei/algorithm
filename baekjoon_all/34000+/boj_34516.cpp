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

string block[4] = {
    "aaab",
    "dabb",
    "ddcb",
    "dccc"
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (n % 4 != 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (int x = 0; x < n; x += 4) {
        for (int y = 0; y < n; y += 4) {
            cout << block[0];
        }

        cout << '\n';

        for (int y = 0; y < n; y += 4) {
            cout << block[1];
        }

        cout << '\n';

        for (int y = 0; y < n; y += 4) {
            cout << block[2];
        }

        cout << '\n';

        for (int y = 0; y < n; y += 4) {
            cout << block[3];
        }

        cout << '\n';
    }

    return 0;
}
