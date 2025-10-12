// Solve 2025-10-12

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

string board[50][5];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 5; x++) {
            cin >> board[i][x];
        }
    }

    int min_diff = INF;
    pii idx_of_min_diff = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = 0;

            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 7; y++) {
                    if (board[i][x][y] != board[j][x][y]) {
                        diff++;
                    }
                }
            }

            if (diff < min_diff) {
                min_diff = diff;
                idx_of_min_diff = {i + 1, j + 1};
            }
        }
    }

    cout << idx_of_min_diff.first << ' ' << idx_of_min_diff.second << '\n';
    return 0;
}
