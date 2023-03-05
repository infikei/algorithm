#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pi3 = pair<int, pii>;

const int INF = 1e9;
const ll LLINF = 4e18;
int vertex, edge;
vector<pi3> edges;
vector<int> dists;

bool bellman_ford(int s) {
    dists.assign(vertex + 1, INF);
    dists[s] = 0;

    // 최단거리를 (n - 1)번 반복하여 갱신
    for (int iter = 1; iter < vertex; iter++) {
        for (auto now_edge : edges) {
            int from = now_edge.first;
            if (dists[from] == INF) continue;
            int to = now_edge.second.first;
            if (dists[to] > dists[from] + now_edge.second.second) {
                dists[to] = dists[from] + now_edge.second.second;
            }
        }
    }

    // 음의 사이클이 있는지 확인하고 있으면 false 반환
    for (auto now_edge : edges) {
        int from = now_edge.first;
        if (dists[from] == INF) continue;
        int to = now_edge.second.first;
        if (dists[to] > dists[from] + now_edge.second.second) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int start;
    cin >> vertex >> edge >> start;

    for (int i = 0; i < edge; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges.push_back({ from, { to, dist } });
        edges.push_back({ to, { from, dist } }); // 양방향일 경우
    }

    bool completed = bellman_ford(start);
    if (completed) {
        cout << "음의 사이클이 없으므로 dists에 결과가 저장됨.\n";
        for (int i = 1; i <= vertex; i++) {
            cout << dists[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "음의 사이클이 있음.\n";
    }

    return 0;
}