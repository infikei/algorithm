// Solve 2025-02-02
// Update 2025-03-03

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

const int INF = 1e9;

int dist[101][101];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            dist[u][v] = INF;
        }

        dist[u][u] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    for (int mid = 1; mid <= n; mid++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                dist[from][to] = min(dist[from][to], dist[from][mid] + dist[mid][to]);
            }
        }
    }

    int min_chicken_dist_sum = INF;
    int chicken_pos[2];

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            int cur_chicken_dist_sum = 0;

            for (int u = 1; u <= n; u++) {
                cur_chicken_dist_sum += min(dist[a][u], dist[b][u]);
            }

            if (cur_chicken_dist_sum < min_chicken_dist_sum) {
                min_chicken_dist_sum = cur_chicken_dist_sum;
                chicken_pos[0] = a;
                chicken_pos[1] = b;
            }
        }
    }

    cout << chicken_pos[0] << ' ' << chicken_pos[1] << ' ' << (min_chicken_dist_sum * 2) << '\n';

    return 0;
}
