// Solve 2023-02-20

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pi3 = pair<int, pii>;
using pi4 = pair<pii, pii>;
using pi5 = pair<int, pi4>;

int n, m, ones;
int graph[10][10];
pii parent[10][10];
priority_queue<pi5, vector<pi5>, greater<pi5> > edges;

pii get_parent(pii k) {
    if (parent[k.first][k.second].first < 0) {
        return k;
    }

    parent[k.first][k.second] = get_parent(parent[k.first][k.second]);
    return parent[k.first][k.second];
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> graph[row][col];
            if (graph[row][col] == 1) {
                ones++;
            }
            parent[row][col] = { -1, 0 };
        }
    }

    for (int row = 0; row < n; row++) {
        int prev_col = -1;
        for (int col = 0; col < m; col++) {
            if (graph[row][col] == 0) continue;
            if (prev_col != -1 && col - prev_col != 2) {
                edges.push({ col - prev_col - 1, { { row, prev_col }, { row, col } } });
            }
            prev_col = col;
        }
    }

    for (int col = 0; col < m; col++) {
        int prev_row = -1;
        for (int row = 0; row < n; row++) {
            if (graph[row][col] == 0) continue;
            if (prev_row != -1 && row - prev_row != 2) {
                edges.push({ row - prev_row - 1, { { prev_row, col }, { row, col } } });
            }
            prev_row = row;
        }
    }

    int ans = 0, connected_ones = 0;
    while (!edges.empty()) {
        pi5 edge = edges.top();
        edges.pop();

        pii pu = get_parent(edge.second.first);
        pii pv = get_parent(edge.second.second);

        if (pu != pv) {
            ans += edge.first;
            if (parent[pu.first][pu.second] < parent[pv.first][pv.second]) {
                parent[pu.first][pu.second].first += parent[pv.first][pv.second].first;
                parent[pv.first][pv.second] = pu;
                connected_ones = min(connected_ones, parent[pu.first][pu.second].first);
            }
            else {
                parent[pv.first][pv.second].first += parent[pu.first][pu.second].first;
                parent[pu.first][pu.second] = pv;
                connected_ones = min(connected_ones, parent[pv.first][pv.second].first);
            }
        }
    }

    if (ones != -connected_ones) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}