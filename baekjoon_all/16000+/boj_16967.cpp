// Solve 2025-06-28

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

int h, w, x, y;
int b[600][600];

void input() {
    cin >> h >> w >> x >> y;

    for (int i = 0; i < h + x; i++) {
        for (int j = 0; j < w + y; j++) {
            cin >> b[i][j];
        }
    }
}

void pro() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i >= x && j >= y) {
                b[i][j] -= b[i - x][j - y];
            }

            cout << b[i][j] << ' ';
        }

        cout << '\n';
    }
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
