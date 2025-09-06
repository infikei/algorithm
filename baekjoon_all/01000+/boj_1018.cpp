// Solve 2023-10-14
// Update 2025-09-05

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

    int n, m;
    cin >> n >> m;

    vector<string> board(n, "");

    for (string &row : board) {
        cin >> row;
    }

    int ans = 32;

    for (int i = 7; i < n; i++) {
        for (int j = 7; j < m; j++) {
            int cnt = 0;

            for (int x = i - 7; x <= i; x++) {
                for (int y = j - 7; y <= j; y++) {
                    if ((x + y) % 2 == 0) {
                        if (board[x][y] == 'B')  {
                            cnt++;
                        }
                    }
                    else {
                        if (board[x][y] == 'W')  {
                            cnt++;
                        }
                    }
                }
            }

            ans = min(ans, min(cnt, 64 - cnt));
        }
    }

    cout << ans << '\n';
    return 0;
}
