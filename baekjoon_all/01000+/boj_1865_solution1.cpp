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

const int MAX_N = 500;
int n, m, w, dists[MAX_N + 1];
vector<vector<pii> > graph;

bool transformed_bellman_ford() {
    // 이 문제 한정으로, 시작 정점을 1개로 설정하지 않고 모든 정점을 시작 정점으로 둔다.
    // 이는 다시 말하면 거리 배열 전체를 INF가 아닌 0으로 두고 풀어야 한다는 뜻이다.
    // 자세한 설명은 https://www.acmicpc.net/board/view/72995 에 나와있다.

    // 최단거리를 (n - 1)번 반복하여 갱신
    for (int iter = 1; iter < n; iter++) {
        for (int from = 1; from <= n; from++) {
            for (auto to : graph[from]) {
                if (dists[to.first] > dists[from] + to.second) {
                    dists[to.first] = dists[from] + to.second;
                }
            }
        }
    }

    // 음의 사이클이 있는지 확인하고 있으면 false 반환
    for (int from = 1; from <= n; from++) {
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

    int tc;
    cin >> tc;

    for (int tci = 0; tci < tc; tci++) {
        cin >> n >> m >> w;
        graph.assign(n + 1, vector<pii>());
        for (int i = 0; i < m; i++) {
            int from, to, dist;
            cin >> from >> to >> dist;
            graph[from].push_back({ to, dist });
            graph[to].push_back({ from, dist });
        }
        for (int i = 0; i < w; i++) {
            int from, to, dist;
            cin >> from >> to >> dist;
            graph[from].push_back({ to, -dist });
        }

        bool completed = transformed_bellman_ford();
        cout << (completed ? "NO\n" : "YES\n");
    }

    return 0;
}