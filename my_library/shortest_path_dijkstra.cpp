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

    int n, e, start, finish;
    cin >> n >> e >> start >> finish;

    vector<vector<pii> > edges(n, vector<pii>());

    for (int i = 0; i < e; i++) {
        int edge_from, edge_to, edge_dist;
        cin >> edge_from >> edge_to >> edge_dist;

        edges[edge_from].emplace_back(edge_to, edge_dist);
        edges[edge_to].emplace_back(edge_from, edge_dist); // 간선이 양방향일 경우
    }

    vector<int> dists(n, INF);
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    dists[start] = 0;
    pq_mintop.emplace(0, start);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        // finish까지의 최단거리만 구하는 경우라면 이 이후의 실행은 의미가 없으므로
        // finish에서 반복을 끝내서 시간을 단축한다.
        // 이렇게 하면 finish를 제외한 다른 점들에 대해서는
        // 최단 거리 값이 아닐 수 있다. (중간에 실행을 멈췄으므로)
        if (now == finish) break;

        // 불필요한 탐색은 생략한다.
        if (dists[now] < dist_to_now) continue;

        for (pii edge : edges[now]) {
            int next = edge.first;
            int dist_to_next = dist_to_now + edge.second;

            if (dists[next] > dist_to_next) {
                dists[next] = dist_to_next;
                pq_mintop.emplace(dist_to_next, next);
            }
        }
    }

    return 0;
}
