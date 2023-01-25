#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int MAX_N = 100;
int n, board_min, board_max, ans;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void bfs(int h, int x0, int y0) {
    queue<pii> q;
    q.push(make_pair(x0, y0));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (board[nx][ny] <= h) continue;
            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    fastio;

    // 입력
    cin >> n;
    board_min = 100, board_max = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            board_min = min(board_min, board[i][j]);
            board_max = max(board_max, board[i][j]);
        }
    }

    ans = 1; // 안전한 영역의 개수는 최소 1개이다. (물의 높이가 1 미만인 경우가 항상 존재하므로)
    for (int h = board_min; h < board_max; h++) {
        // 그래프 탐색
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                if (board[i][j] <= h) continue;
                bfs(h, i, j);
                cnt++;
            }
        }
        ans = max(ans, cnt);

        // visited 배열 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
    }

    // 결과 출력
    cout << ans << '\n';

    return 0;
}