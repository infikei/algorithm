#include <iostream>
using namespace std;

int w, h, cnt;
int graph[50][50];
bool visited[50][50];
int dw[8] = {1,1,0,-1,-1,-1,0,1};
int dh[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int h0, int w0) {
    for (int i = 0; i < 8; i++) {
        int h1 = h0 + dh[i];
        int w1 = w0 + dw[i];
        if (h1 < 0 || h1 >= h || w1 < 0 || w1 >= w) {
            continue;
        }
        if (!visited[h1][w1] && graph[h1][w1] == 1) {
            visited[h1][w1] = true;
            dfs(h1, w1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> graph[i][j];
                visited[i][j] = false;
            }
        }

        cnt = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && graph[i][j] == 1) {
                    visited[i][j] = true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}