// Solve 2022-09-14
// Update 2023-02-12

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

const int MAX_N = 100000;
int n, parent[MAX_N + 1];
vector<int> graph[MAX_N + 1];
bool visited[MAX_N + 1];

void bfs() {
    visited[1] = true;
    queue<int> q;
    for (auto next : graph[1]) {
        visited[next] = true;
        parent[next] = 1;
        q.push(next);
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto next : graph[now]) {
            if (visited[next]) continue;
            visited[next] = true;
            parent[next] = now;
            q.push(next);
        }
    }
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}