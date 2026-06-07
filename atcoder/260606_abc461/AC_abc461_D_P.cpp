// Solve 2026-06-06

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

int board[502][502];
int row_psum[502];

int main() {
    FASTIO;

    int h, w, k;
    cin >> h >> w >> k;

    for (int x = 1; x <= h; x++) {
        string s;
        cin >> s;

        for (int y = 1; y <= w; y++) {
            board[x][y] = (s[y - 1] == '1' ? 1 : 0);
            board[x][y] += board[x][y - 1];
        }
    }

    ll cnt = 0;

    for (int y1 = 0; y1 < w; y1++) {
        for (int y2 = y1 + 1; y2 <= w; y2++) {
            for (int x = 1; x <= h; x++) {
                row_psum[x] = row_psum[x - 1] + board[x][y2] - board[x][y1];
                cnt += upper_bound(row_psum, row_psum + x, row_psum[x] - k) - lower_bound(row_psum, row_psum + x, row_psum[x] - k);
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
