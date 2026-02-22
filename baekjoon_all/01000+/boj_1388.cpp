// Solve 2026-02-16

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

string board[50];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    int cnt = 0;

    for (int x = 0; x < n; x++) {
        bool state = false;

        for (int y = 0; y < m; y++) {
            if (board[x][y] == '-') {
                if (!state) {
                    state = true;
                    cnt++;
                }
            }
            else {
                state = false;
            }
        }
    }

    for (int y = 0; y < m; y++) {
        bool state = false;

        for (int x = 0; x < n; x++) {
            if (board[x][y] == '|') {
                if (!state) {
                    state = true;
                    cnt++;
                }
            }
            else {
                state = false;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
