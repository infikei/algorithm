// Solve 2023-02-13

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

const int MAX_V = 100000;
int v, max_node, max_dist;
vector<pii> graph[MAX_V + 1];
bool visited[MAX_V + 1];

void bfs(int s, bool initialize) {
    if (initialize) {
        for (int i = 1; i <= v; i++) {
            visited[i] = false;
        }
    }

    visited[s] = true;
    queue<pii> q;
    q.push({ s, 0 });

    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        for (auto next : graph[now.first]) {
            int next_node = next.first;
            if (visited[next_node]) continue;
            visited[next_node] = true;
            int next_dist = next.second + now.second;
            if (next_dist > max_dist) {
                max_dist = next_dist;
                max_node = next_node;
            }
            q.push({ next_node, next_dist });
        }
    }
}

int main() {
    FASTIO;

    cin >> v;
    for (int i = 1; i <= v; i++) {
        int a, b, dist;
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> dist;
            graph[a].push_back({ b, dist });
            graph[b].push_back({ a, dist });
        }
    }

    bfs(1, false);
    max_dist = 0;
    bfs(max_node, true);
    cout << max_dist << '\n';

    return 0;
}