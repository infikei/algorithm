// Solve 2023-11-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;

struct FD{
    int fatigue, dist;

    FD(int fatigue, int dist) : fatigue(fatigue), dist(dist) {}

    FD operator+(const FD &rhs) const {
        return { fatigue + rhs.fatigue, dist + rhs.dist };
    }

    bool operator<(const FD &rhs) const {
        if (fatigue != rhs.fatigue) {
            return fatigue < rhs.fatigue;
        }
        return dist < rhs.dist;
    }

    bool operator>(const FD &rhs) const {
        if (fatigue != rhs.fatigue) {
            return fatigue > rhs.fatigue;
        }
        return dist > rhs.dist;
    }
};

int main() {
    FASTIO;

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, FD>>> roads(n, vector<pair<int, FD>>());
    vector<int> minimum_fatigue(n, 101);

    for (int i = 0; i < m; i++) {
        int u, v, a, c, b;
        cin >> u >> v >> a >> c >> b;

        if (a < minimum_fatigue[u]) {
            minimum_fatigue[u] = a;
            roads[u].clear();
            roads[u].emplace_back(v, FD(a, c));
        }
        else if (a == minimum_fatigue[u]) {
            roads[u].emplace_back(v, FD(a, c));
        }

        if (b < minimum_fatigue[v]) {
            minimum_fatigue[v] = b;
            roads[v].clear();
            roads[v].emplace_back(u, FD(b, c));
        }
        else if (b == minimum_fatigue[v]) {
            roads[v].emplace_back(u, FD(b, c));
        }
    }

    vector<FD> fd(n, FD(INF, INF));
    fd[s] = FD(0, 0);
    int iter = n - 1;

    while (iter > 0) {
        iter--;

        for (int u = 0; u < n; u++) {
            if (fd[u].fatigue == INF) continue;

            for (auto road : roads[u]) {
                int nu = road.first;
                FD fd_update = fd[u] + road.second;

                if (fd[nu] > fd_update) {
                    fd[nu] = fd_update;
                }
            }
        }
    }

    // 음의 사이클이 존재하고 음의 사이클에서 정점 t로 이동하는 경로가 존재하는지 여부
    bool flag_has_negative_cycle = false;

    if (fd[t].fatigue != INF) {
        queue<int> bfs_que;
        vector<bool> visited(n, false);

        for (int u = 0; u < n; u++) {
            if (fd[u].fatigue == INF) continue;

            for (auto road : roads[u]) {
                int nu = road.first;
                FD fd_update = fd[u] + road.second;

                if (fd[nu] > fd_update) {
                    fd[nu] = fd_update;

                    if (!visited[nu]) {
                        visited[nu] = true;
                        bfs_que.push(nu);
                    }
                }
            }
        }

        while (!bfs_que.empty()) {
            int u = bfs_que.front();
            bfs_que.pop();

            for (auto road : roads[u]) {
                int nu = road.first;

                if (!visited[nu]) {
                    visited[nu] = true;
                    bfs_que.push(nu);
                }
            }
        }

        if (visited[t]) {
            flag_has_negative_cycle = true;
        }
    }

    if (fd[t].fatigue == INF) {
        cout << "VOID\n";
    }
    else if (flag_has_negative_cycle) {
        cout << "UNBOUND\n";
    }
    else {
        cout << fd[t].fatigue << ' ' << fd[t].dist << '\n';
    }

    return 0;
}
