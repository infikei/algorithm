// Solve 2026-01-04

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

int h, n, hn;
bool ladder[31][11];
int mn = 4;

bool check_ladder() {
    for (int c = 1; c < n; c++) {
        int cur = c;

        for (int r = 1; r <= h; r++) {
            if (ladder[r][cur]) {
                cur++;
            }
            else if (ladder[r][cur - 1]) {
                cur--;
            }
        }

        if (cur != c) {
            return false;
        }
    }

    return true;
}

void recur(int level, int idx_from) {
    for (int i = idx_from; i < hn; i++) {
        if (level >= mn) return;

        int r = i / n + 1;
        int c = i % n + 1;

        if (c == n || ladder[r][c - 1] || ladder[r][c] || ladder[r][c + 1]) continue;

        ladder[r][c] = true;

        if (check_ladder()) {
            mn = min(mn, level);
        }

        recur(level + 1, i + 1);
        ladder[r][c] = false;
    }
}

int main() {
    FASTIO;

    int m;
    cin >> n >> m >> h;
    hn = h * n;

    while (m-- > 0) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    if (check_ladder()) {
        mn = 0;
    }

    recur(1, 0);
    cout << (mn == 4 ? -1 : mn) << '\n';
    return 0;
}
