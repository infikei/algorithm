#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int ans, board[101];
bool visited[101];
queue<int> bfs_queue;

void bfs() {
    visited[1] = true;
    bfs_queue.push(1);

    while (true) {
        ans++;

        int i_end = bfs_queue.size();
        for (int i = 0; i < i_end; i++) {
            int now = bfs_queue.front();
            bfs_queue.pop();

            for (int j = 1; j < 7; j++) {
                int next = now + j;
                if (next < 101 && board[next] != 0) {
                    next = board[next];
                }
                if (next >= 100) {
                    return;
                }
                if (visited[next]) {
                    continue;
                }
                visited[next] = true;
                bfs_queue.push(next);
            }
        }
    }
}

int main() {
    fastio;

    int N, M;
    cin >> N >> M;
    int NM = N + M;

    int u, v;
    for (int i = 0; i < NM; i++) {
        cin >> u >> v;
        board[u] = v;
    }

    bfs();

    cout << ans << '\n';

    return 0;
}