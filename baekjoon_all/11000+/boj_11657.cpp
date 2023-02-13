// Solve 2023-01-09
// Update 2023-02-13

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
using pi3 = pair<int, pii>;

const int MAX_N = 500;
int n, m;
ll dists[MAX_N + 1]; // int로 할 경우에는 음수 범위에서 오버플로우가 발생하므로 long long으로 설정해야 한다.
vector<pi3> edges;

bool bellman_ford(int s) {
    for (int i = 1; i <= n; i++) {
        dists[i] = LLINF; // 여기서는 LLINF 대신 INF를 써도 통과한다.
    }
    dists[s] = 0;

    for (int iter = 1; iter < n; iter++) {
        for (auto now_edge : edges) {
            int from = now_edge.first;
            if (dists[from] == LLINF) continue;
            int to = now_edge.second.first;
            if (dists[to] > dists[from] + now_edge.second.second) {
                dists[to] = dists[from] + now_edge.second.second;
            }
        }
    }

    for (auto now_edge : edges) {
        int from = now_edge.first;
        if (dists[from] == LLINF) continue;
        int to = now_edge.second.first;
        if (dists[to] > dists[from] + now_edge.second.second) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges.push_back({ from, { to, dist }});
    }

    bool completed = bellman_ford(1);
    if (completed) {
        for (int i = 2; i <= n; i++) {
            cout << (dists[i] == LLINF ? -1 : dists[i]) << '\n';
        }
    }
    else cout << -1 << '\n';

    return 0;
}