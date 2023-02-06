#include <iostream>
using namespace std;

int M, N, K, cnt;
int graph[50][50];

void input() {
    cin >> M >> N >> K;
    cnt = 0;

    for (int row = 0; row < 50; row++) {
        for (int col = 0; col < 50; col++) {
            graph[row][col] = 0;
        }
    }

    for (int k = 0; k < K; k++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
    }
}

void dfs(int x, int y) {
    graph[x][y] = 2;

    if (x > 0 && graph[x - 1][y] == 1) {
        dfs(x - 1, y);
    }
    if (x < M - 1 && graph[x + 1][y] == 1) {
        dfs(x + 1, y);
    }
    if (y > 0 && graph[x][y - 1] == 1) {
        dfs(x, y - 1);
    }
    if (y < N - 1 && graph[x][y + 1] == 1) {
        dfs(x, y + 1);
    }
}

void solve() {
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            if (graph[row][col] == 1) {
                dfs(row, col);
                cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        input();
        solve();
        cout << cnt << '\n';
    }

    return 0;
}