// Solve 2023-01-06
// Update 2023-11-23

// 풀이 방법에 관한 글 : https://www.acmicpc.net/board/view/38887
// 1. 다익스트라 알고리즘
// 2. 0-1 BFS : 큐 대신 덱을 사용하여 가중치가 0인 간선에 연결된 정점은 덱의 맨 뒤가 아닌 맨 앞에 넣는 방법
// 3. 2배를 별도의 간선으로 생각하지 않고, +1이나 -1에 의한 좌표를 큐에 넣을 때 그 좌표의 2의 거듭제곱 배인 좌표들을 전부 큐에 넣는 방법
// 아래 풀이는 2번째 방법인 0-1 BFS를 이용한 풀이이다.

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MAX_N = 100000;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<int> dist(MAX_N + 1, 0);
    vector<bool> visited(MAX_N + 1, false);
    deque<int> dque;

    visited[n] = true;
    dque.push_back(n);

    while (!dque.empty()) {
        int now = dque.front();
        int now_dist = dist[now];
        dque.pop_front();

        if (now == k) break;

        int next = now * 2;

        if (next <= MAX_N && !visited[next]) {
            dist[next] = now_dist;
            visited[next] = true;
            dque.push_front(next);
        }

        next = now - 1;

        if (next >= 0 && !visited[next]) {
            dist[next] = now_dist + 1;
            visited[next] = true;
            dque.push_back(next);
        }

        next = now + 1;

        if (next <= MAX_N && !visited[next]) {
            dist[next] = now_dist + 1;
            visited[next] = true;
            dque.push_back(next);
        }
    }

    cout << dist[k] << '\n';

    return 0;
}
