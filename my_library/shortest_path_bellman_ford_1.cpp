#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e9; // (정점의 개수 * 간선의 개수 * 간선의 가중치의 최댓값) 보다 크게 설정

int main() {
    FASTIO;

    int n; // 정점의 개수 (각 정점은 0 이상 n - 1 이하의 값을 가진다)
    int m; // 간선의 개수
    int start; // 시작 정점의 번호
    cin >> n >> m >> start;

    // 간선 입력

    vector<vector<pii>> edges(n, vector<pii>());

    for (int i = 0; i < m; i++) {
        int edge_from, edge_to, edge_cost;
        cin >> edge_from >> edge_to >> edge_cost;

        edges[edge_from].emplace_back(edge_to, edge_cost);
        edges[edge_to].emplace_back(edge_from, edge_cost); // 간선이 양방향일 경우
    }

    // 벨만-포드 알고리즘
    // 모든 간선에 대해 거리값을 업데이트하는 작업을 (정점의 개수 - 1) 회 반복

    vector<ll> cost(n, INF); // 모든 정점의 거리 값을 무한으로 설정
    cost[start] = 0; // 시작 정점의 거리 값을 0으로 설정
    int iter = n - 1; // 반복할 횟수는 (정점의 개수 - 1) 로 설정

    // (정점의 개수 - 1) 회 반복
    while (iter > 0) {
        iter--;

        // 모든 정점에 대해 반복
        for (int u = 0; u < n; u++) {
            // 현재 정점을 아직 방문하지 않은 경우 skip
            if (cost[u] == INF) continue;

            // 현재 정점에 연결된 모든 간선에 대해 거리값 업데이트
            for (pii edge : edges[u]) {
                int nu = edge.first;
                ll cost_update = cost[u] + edge.second;

                if (cost[nu] > cost_update) {
                    cost[nu] = cost_update;
                }
            }
        }
    }

    // 그래프에 음의 사이클이 존재하는지 확인

    bool flag_has_negative_cycle = false;

    // 모든 정점에 대해 반복
    for (int u = 0; u < n; u++) {
        // 현재 정점을 아직 방문하지 않은 경우 skip
        if (cost[u] == INF) continue;

        // 현재 정점에 연결된 모든 간선에 대해 검사
        for (pii edge : edges[u]) {
            int nu = edge.first;
            ll cost_update = cost[u] + edge.second;

            // 여전히 거리 값이 줄어드는 정점이 존재한다면 그래프에 음의 사이클이 존재함
            if (cost[nu] > cost_update) {
                flag_has_negative_cycle = true;
                break;
            }
        }

        if (flag_has_negative_cycle) break;
    }

    // 결과 출력

    if (flag_has_negative_cycle) {
        cout << "음의 사이클이 존재한다.\n";
    }
    else {
        cout << "음의 사이클이 존재하지 않는다.\n";

        for (int u = 0; u < n; u++) {
            cout << u << " : " << cost[u] << '\n';
        }
    }

    return 0;
}
