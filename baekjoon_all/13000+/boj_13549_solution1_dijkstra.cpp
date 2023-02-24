// Solve 2023-01-06
// Update 2023-02-11

// 풀이 방법에 관한 글 : https://www.acmicpc.net/board/view/38887
// 1. 다익스트라 알고리즘
// 2. 0-1 BFS : 큐 대신 덱을 사용하여 가중치가 0인 간선에 연결된 정점은 덱의 맨 뒤가 아닌 맨 앞에 넣는 방법
// 3. 2배를 별도의 간선으로 생각하지 않고, +1이나 -1에 의한 좌표를 큐에 넣을 때 그 좌표의 2의 거듭제곱 배인 좌표들을 전부 큐에 넣는 방법
// 아래 풀이는 1번째 방법인 다익스트라 알고리즘을 이용한 풀이이다.

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9;
const int MAX_N = 100000;
int n, k;
int dist[MAX_N + 1];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;

    for (int i = 0; i <= MAX_N; i++) {
        dist[i] = INF;
    }

    dist[n] = 0;
    pq_mintop.push({ 0, n });

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int now_dist = pq_mintop.top().first;
        pq_mintop.pop();

        int next = now - 1;
        if (next >= 0 && dist[next] > now_dist + 1) {
            dist[next] = now_dist + 1;
            pq_mintop.push({ now_dist + 1, next });
        }

        next = now + 1;
        if (next <= MAX_N && dist[next] > now_dist + 1) {
            dist[next] = now_dist + 1;
            pq_mintop.push({ now_dist + 1, next });
        }

        next = now * 2;
        if (next <= MAX_N && dist[next] > now_dist) {
            dist[next] = now_dist;
            pq_mintop.push({ now_dist, next });
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> k;

    dijkstra();

    cout << dist[k] << '\n';

    return 0;
}