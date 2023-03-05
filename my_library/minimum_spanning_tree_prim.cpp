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

const int INF = 1e9;
const ll LLINF = 4e18;
const int MAX_V = 1000000;
int v, e;
vector<pii> edges[MAX_V];
int dists[MAX_V];
bool visited[MAX_V];

int main() {
    FASTIO;

    // 여기에서는 프림 알고리즘을 이용하였다.

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        edges[from].push_back({ to, dist });
        edges[to].push_back({ from, dist });
    }

    for (int i = 0; i < v; i++) {
        dists[i] = INF;
    }

    int ans = 0; // 최소 비용 신장 트리를 만들기 위한 비용
    visited[0] = true;
    for (auto edge : edges[0]) {
        dists[edge.first] = edge.second;
    }

    for (int iter = v - 1; iter > 0; iter--) {
        int min_dist = INF;
        int min_idx = -1;

        for (int i = 0; i < v; i++) {
            if (visited[i]) continue;
            if (min_dist > dists[i]) {
                min_dist = dists[i];
                min_idx = i;
            }
        }

        ans += min_dist;
        visited[min_idx] = true;

        for (auto edge : edges[min_idx]) {
            if (visited[edge.first]) continue;
            if (dists[edge.first] > edge.second) {
                dists[edge.first] = edge.second;
            }
        }
    }

    return 0;
}