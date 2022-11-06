#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int N, M;
string graph[100];
bool visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x_start = 0, int y_start = 0) {
    queue<pii> q;
    q.push(make_pair(x_start, y_start));
    q.push(make_pair(-1, -1));
    visited[x_start][y_start] = true;
    int res = 1;

    while (true) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return res;
        }

        if (x == -1 && y == -1) {
            q.push(make_pair(-1, -1));
            res++;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // next x
            int ny = y + dy[i]; // next y
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && graph[nx][ny] == '1' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        cin >> graph[row];
    }

    cout << bfs() << '\n';

    return 0;
}