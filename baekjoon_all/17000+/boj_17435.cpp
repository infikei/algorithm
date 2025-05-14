// Solve 2025-05-14

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int f[19][200001];

int main() {
    FASTIO;

    int m;
    cin >> m;

    for (int x = 1; x <= m; x++) {
        cin >> f[0][x];
    }

    for (int i = 1; i < 19; i++) {
        for (int x = 1; x <= m; x++) {
            f[i][x] = f[i - 1][f[i - 1][x]];
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int n, x;
        cin >> n >> x;

        for (int i = 0; i < 19; i++) {
            if (n & (1 << i)) {
                x = f[i][x];
            }
        }

        cout << x << '\n';
    }

    return 0;
}
