// Solve 2023-02-19

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

const int MAX_V = 10000;
int v, e;
vector<pii> edges[MAX_V + 1];
int dist[MAX_V + 1];
bool visited[MAX_V + 1];

int main() {
    FASTIO;

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }

    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }

    visited[1] = true;
    int ans = 0;
    for (auto edge : edges[1]) {
        dist[edge.first] = edge.second;
    }

    for (int iter = v - 1; iter > 0; iter--) {
        int min_dist = INF;
        int min_idx = 0;
        for (int i = 1; i <= v; i++) {
            if (visited[i]) continue;
            if (min_dist > dist[i]) {
                min_dist = dist[i];
                min_idx = i;
            }
        }

        visited[min_idx] = true;
        ans += min_dist;
        for (auto edge : edges[min_idx]) {
            if (visited[edge.first]) continue;
            if (dist[edge.first] > edge.second) {
                dist[edge.first] = edge.second;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}