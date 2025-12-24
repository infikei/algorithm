// Solve 2025-12-23

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

int n, m, r, s;
int board[20][20];
int prefix[20][20];
int selected[20];
int mn = INF;

bool check(int limit) {
    vector<int> vs(r + 2);
    vector<int> v(r + 2);
    int cnt = 0;

    for (int y = 1; y <= m; y++) {
        for (int i = 1; i <= r + 1; i++) {
            int x0 = selected[i - 1];
            int x = selected[i];
            v[i] = prefix[x][y] - prefix[x0][y];
            vs[i] += v[i];
        }

        if (*max_element(v.begin(), v.end()) > limit) {
            return false;
        }

        if (*max_element(vs.begin(), vs.end()) > limit) {
            cnt++;

            if (cnt > s) {
                return false;
            }

            for (int i = 1; i <= r + 1; i++) {
                vs[i] = v[i];
            }
        }
    }

    return true;
}

void recur(int depth, int idx_from) {
    if (depth == r + 1) {
        int low = 0;
        int high = mn;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(mid)) {
                mn = min(mn, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return;
    }

    for (int i = idx_from; i < n; i++) {
        selected[depth] = i;
        recur(depth + 1, i + 1);
    }
}

int main() {
    FASTIO;

    cin >> n >> m >> r >> s;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
            prefix[x][y] = board[x][y] + prefix[x - 1][y];
        }
    }

    selected[r + 1] = n;
    recur(1, 1);
    cout << mn << '\n';
    return 0;
}
