// Solve 2023-02-18
// Update 2025-02-25

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const int BOARD_MAX = 500000;
bool visited[BOARD_MAX + 1][2];

int bfs(int n, int k) {
    if (n == k) return 0;

    queue<int> que;
    que.push(n);
    visited[n][0] = 0;
    int moved_cnt = 0;

    while (true) {
        moved_cnt++;
        k += moved_cnt;

        if (k > BOARD_MAX) break;

        int moved_cnt2 = moved_cnt & 1;
        int iter = SIZE(que);

        while (iter-- > 0) {
            int cur = que.front();
            que.pop();

            int nxt = cur - 1;

            if (nxt >= 0 && !visited[nxt][moved_cnt2]) {
                visited[nxt][moved_cnt2] = true;
                que.push(nxt);
            }

            nxt = cur + 1;

            if (nxt <= BOARD_MAX && !visited[nxt][moved_cnt2]) {
                visited[nxt][moved_cnt2] = true;
                que.push(nxt);
            }

            nxt = cur * 2;

            if (nxt <= BOARD_MAX && !visited[nxt][moved_cnt2]) {
                visited[nxt][moved_cnt2] = true;
                que.push(nxt);
            }
        }

        if (visited[k][moved_cnt2]) {
            return moved_cnt;
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
