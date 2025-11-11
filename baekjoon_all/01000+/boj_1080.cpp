// Solve 2025-11-10

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

int a[50][50];
int b[50][50];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            char c;
            cin >> c;
            a[x][y] = c - '0';
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            char c;
            cin >> c;
            b[x][y] = c - '0';
        }
    }

    int cnt = 0;

    for (int x = 2; x < n; x++) {
        for (int y = 2; y < m; y++) {
            if (a[x - 2][y - 2] == b[x - 2][y - 2]) continue;

            cnt++;

            for (int nx = x - 2; nx <= x; nx++) {
                for (int ny = y - 2; ny <= y; ny++) {
                    a[nx][ny] ^= 1;
                }
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (a[x][y] != b[x][y]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
