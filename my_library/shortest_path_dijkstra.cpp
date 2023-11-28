#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9; // (정점의 개수 * 간선의 가중치의 최댓값) 보다 크게 설정

int main() {
    FASTIO;

    int n; // 정점의 개수 (각 정점은 0 이상 n - 1 이하의 값을 가진다)
    int m; // 간선의 개수
    int start; // 시작 정점의 번호
    int finish; // 도착 정점의 번호
    cin >> n >> m >> start >> finish;

    // 간선 입력

    vector<vector<pii>> edges(n, vector<pii>());

    for (int i = 0; i < m; i++) {
        int edge_from, edge_to, edge_dist;
        cin >> edge_from >> edge_to >> edge_dist;

        edges[edge_from].emplace_back(edge_to, edge_dist);
        edges[edge_to].emplace_back(edge_from, edge_dist); // 간선이 양방향일 경우
    }

    // 다익스트라 알고리즘

    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq_mintop;
    dist[start] = 0;
    pq_mintop.emplace(0, start);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        // 도착 정점의 최단거리만 구하는 경우라면 이 이후의 실행은 의미가 없으므로
        // 현재 정점이 도착 정점인 경우 반복을 끝내서 시간을 단축한다.
        // 이렇게 하면 도착 정점을 제외한 다른 점들에 대해서는 정확한 최단 거리를 구할 수 없으므로
        // 모든 정점에 대해 최단 거리를 구해야 하는 경우 아래의 break 문을 코드에서 제거한다.
        if (now == finish) break;

        // 불필요한 탐색은 생략한다.
        if (dist[now] < dist_to_now) continue;

        for (pii edge : edges[now]) {
            int next = edge.first;
            int dist_to_next = dist_to_now + edge.second;

            if (dist[next] > dist_to_next) {
                dist[next] = dist_to_next;
                pq_mintop.emplace(dist_to_next, next);
            }
        }
    }

    // 결과 출력

    cout << start << "부터 " << finish << "까지의 거리는 " << dist[finish] << "이다.\n";

    return 0;
}
