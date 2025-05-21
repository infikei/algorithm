// Solve 2025-05-19

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

int from[100001];
int parent[30][100001];

int main() {
    FASTIO;

    int n, k, m;
    cin >> n >> k >> m;

    m--;

    for (int i = 1; i <= n; i++) {
        cin >> from[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> parent[0][i];
    }

    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= k; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        int cur = from[i];

        for (int j = 0; j < 30; j++) {
            if (m & (1 << j)) {
                cur = parent[j][cur];
            }
        }

        cout << cur << ' ';
    }

    cout << '\n';

    return 0;
}
