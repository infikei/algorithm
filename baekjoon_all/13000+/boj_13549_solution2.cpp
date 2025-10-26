// Solve 2023-01-06
// Update 2025-10-26

// 풀이 방법에 관한 글 : https://www.acmicpc.net/board/view/38887
// 1. 다익스트라 알고리즘
// 2. 0-1 BFS : 큐 대신 덱을 사용하여 가중치가 0인 간선에 연결된 정점은 덱의 맨 뒤가 아닌 맨 앞에 넣는 방법
// 3. 2배를 별도의 간선으로 생각하지 않고, +1이나 -1에 의한 좌표를 큐에 넣을 때 그 좌표의 2의 거듭제곱 배인 좌표들을 전부 큐에 넣는 방법

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dist[100001];
bool visited[100001];

int bfs(int n, int k) {
    int a[3] = {2, 1, 1};
    int b[3] = {0, -1, 1};
    int v[3] = {0, 1, 1};

    memset(dist, 0x3f, sizeof dist);
    deque<int> dque;
    dque.push_back(n);
    dist[n] = 0;

    while (!dque.empty()) {
        int cur = dque.front();
        dque.pop_front();

        if (cur == k) return dist[cur];
        if (visited[cur]) continue;

        visited[cur] = true;

        for (int d = 0; d < 3; d++) {
            int nxt = cur * a[d] + b[d];
            int nxt_dist = dist[cur] + v[d];

            if (nxt < 0 || nxt > 100000 || visited[nxt]) continue;

            if (dist[cur] + v[d] < dist[nxt]) {
                dist[nxt] = dist[cur] + v[d];

                if (v[d] == 0) dque.push_front(nxt);
                else dque.push_back(nxt);
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    cout << bfs(n, k) << '\n';
    return 0;
}
