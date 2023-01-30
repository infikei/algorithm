#include <iostream>
#include <queue>
using namespace std;

bool graph[101][101] = {false};
bool visited[101] = {false};
int N, M, ans;

void input() {
    cin >> N;
    cin >> M;
    int from, to;
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        graph[from][to] = true;
        graph[to][from] = true;
    }
}

void BFS() {
    queue<int> q;
    q.push(1);
    ans = -1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (!visited[now]) {
            visited[now] = true;
            ans++;
            for (int i = 1; i <= N; i++) {
                if (graph[now][i] && !visited[i]) {
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    BFS();

    cout << ans << '\n';

    return 0;
}