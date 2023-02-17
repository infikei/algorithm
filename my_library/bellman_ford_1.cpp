#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

int vertex, edge;
vector<vector<pii> > graph;
vector<int> dists;

bool bellman_ford(int s) {
    dists.assign(vertex + 1, INF);
    dists[s] = 0;

    // 최단거리를 (n - 1)번 반복하여 갱신
    for (int iter = 1; iter < vertex; iter++) {
        for (int from = 1; from <= vertex; from++) {
            if (dists[from] == INF) continue;
            for (auto to : graph[from]) {
                if (dists[to.first] > dists[from] + to.second) {
                    dists[to.first] = dists[from] + to.second;
                }
            }
        }
    }

    // 음의 사이클이 있는지 확인하고 있으면 false 반환
    for (int from = 1; from <= vertex; from++) {
        if (dists[from] == INF) continue;
        for (auto to : graph[from]) {
            if (dists[to.first] > dists[from] + to.second) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    FASTIO;

    int start;
    cin >> vertex >> edge >> start;

    graph.assign(vertex + 1, vector<pii>());
    for (int i = 0; i < edge; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from].push_back({ to, dist });
        graph[to].push_back({ from, dist }); // 양방향일 경우
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