#include <iostream>
#include <queue>
using namespace std;

bool graph[1001][1001] = {false};
bool visited[1001] = {false};
int N, M, visited_N, cnt;

void input() {
    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        graph[from][to] = true;
        graph[to][from] = true;
    }
}

void BFS() {
    int now = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            now = i;
            break;
        }
    }

    queue<int> q;
    q.push(now);

    while (!q.empty()) {
        now = q.front();
        q.pop();

        if (!visited[now]) {
            visited[now] = true;
            visited_N++;
            for (int i = 1; i <= N; i++) {
                if (graph[now][i] && !visited[i]) {
                    q.push(i);
                }
            }
        }
    }

    cnt++;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    visited_N = 0;
    cnt = 0;

    while (visited_N < N) {
        BFS();
    }

    cout << cnt << '\n';

    return 0;
}