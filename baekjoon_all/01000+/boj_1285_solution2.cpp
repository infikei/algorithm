// Solve 2025-12-20

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

int board[20];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        string s;
        cin >> s;

        for (int y = 0; y < n; y++) {
            if (s[y] == 'T') {
                board[x] |= (1 << y);
            }
        }
    }

    int mn = n * n;

    for (int b = 0; b < (1 << (n - 1)); b++) {
        int cnt = 0;

        for (int x = 0; x < n; x++) {
            int c = __builtin_popcount(board[x] ^ b);
            cnt += min(c, n - c);
        }

        mn = min(mn, cnt);
    }

    cout << mn << '\n';
    return 0;
}
