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

int n;
int board[1000][1000];

ll get_val(int h) {
    ll ret = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            ret += min(h, board[x][y]);
        }
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> n;
    ll board_sum = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int v;
            cin >> v;
            board[x][y] = v;
            board_sum += v;
        }
    }

    ll half = (board_sum + 1) / 2;
    int mn = 10000000;
    int low = 0;
    int high = 10000000;

    while (low <= high) {
        int mid = (low + high) / 2;
        ll val = get_val(mid);

        if (val >= half) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << mn << '\n';
    return 0;
}
