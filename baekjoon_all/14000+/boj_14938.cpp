// Solve 2023-01-11
// Update 2025-09-30

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

void floyd_warshall(int n, vector<vector<int>>& dist) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

int main() {
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> item(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < r; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    floyd_warshall(n, dist);
    int max_item = 0;

    for (int i = 1; i <= n; i++) {
        int cur_item = 0;

        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) {
                cur_item += item[j];
            }
        }

        max_item = max(max_item, cur_item);
    }

    cout << max_item << '\n';
    return 0;
}
