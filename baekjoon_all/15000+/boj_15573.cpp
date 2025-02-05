// Solve 2025-02-05

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int board[1000][1000];
bool visited[1000][1000];

void init_visited(int n, int m) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            visited[x][y] = false;
        }
    }
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }

    int low = 0; // 항상 false (캘 수 있는 광물의 개수가 항상 k개 미만이다)
    int high = 1000000; // 항상 true (캘 수 있는 광물의 개수가 항상 k개 이상이다)

    while (low + 1 < high) {
        // 강도를 mid 값으로 설정하면 얼마나 많은 광물을 캘 수 있는지 구한다.
        int mid = (low + high) / 2;
        int cnt = 0; // 강도를 mid 값으로 설정할 경우 캘 수 있는 광물의 개수

        init_visited(n, m); // 방문 배열 초기화
        queue<pii> bfs_que; // 캘 수 있는 광물의 좌표를 저장할 큐

        // 공기와 접한 칸들 중에서 캘 수 있는 광물의 좌표를 큐에 추가한다.

        for (int y = 0; y < m; y++) {
            visited[0][y] = true;

            if (board[0][y] <= mid) {
                bfs_que.emplace(0, y);
                cnt++;
            }
        }

        for (int x = 1; x < n; x++) {
            visited[x][0] = true;
            visited[x][m - 1] = true;

            if (board[x][0] <= mid) {
                bfs_que.emplace(x, 0);
                cnt++;
            }
            
            if (board[x][m - 1] <= mid) {
                bfs_que.emplace(x, m - 1);
                cnt++;
            }
        }

        // 캘 수 있는 모든 광물을 BFS로 탐색한다.

        while (!bfs_que.empty()) {
            pii cur = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.first + dx[d];
                int ny = cur.second + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;

                if (board[nx][ny] <= mid) {
                    bfs_que.emplace(nx, ny);
                    cnt++;
                }
            }
        }

        // 캘 수 있는 광물의 개수가 k개 이상인 강도는 high 값에 배정하고, 그렇지 않은 강도는 low 값에 배정한다.

        if (cnt >= k) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    println(high);

    return 0;
}
