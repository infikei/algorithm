#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int l, x, y, x_end, y_end;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
bool visited[300][300];

void initialize() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            visited[i][j] = false;
        }
    }
}

int bfs() {
    int res = 0;
    queue<pii> q;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    q.push(make_pair(-1, -1));

    while (true) {
        pii now = q.front();
        q.pop();

        if (now.first == -1) {
            res++;
            q.push(make_pair(-1, -1));
            continue;
        }

        if (now.first == x_end && now.second == y_end) {
            return res;
        }

        for (int i = 0; i < 8; i++) {
            int x_next = now.first + dx[i];
            int y_next = now.second + dy[i];

            if (x_next >= 0 && x_next < l && y_next >= 0 && y_next < l && !visited[x_next][y_next]) {
                visited[x_next][y_next] = true;
                q.push(make_pair(x_next, y_next));
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
        cin >> l >> x >> y >> x_end >> y_end;

        initialize();
        cout << bfs() << '\n';
    }

    return 0;
}