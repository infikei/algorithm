#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool map[1001][1001] = {false};
bool visited[1001] = {false};
int N, M, V;

void reset_visited() {
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

void DFS() {
    stack<int> s;
    s.push(V);

    int now;
    while (!s.empty()) {
        now = s.top();
        s.pop();
        if (!visited[now]) {
            visited[now] = true;
            cout << now << ' ';
            for (int i = N; i >= 1; i--) { // N부터 1까지 검사하며 추가
                if (!visited[i] && map[now][i]) {
                    s.push(i);
                }
            }
        }
    }

    cout << '\n';
}

void BFS() {
    queue<int> q;
    q.push(V);

    int now;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        if (!visited[now]) {
            visited[now] = true;
            cout << now << ' ';
            for (int i = 1; i <= N; i++) { // 1부터 N까지 검사하며 추가
                if (!visited[i] && map[now][i]) {
                    q.push(i);
                }
            }
        }
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M >> V;
    int from, to;
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        map[from][to] = true;
        map[to][from] = true;
    }

    DFS();

    reset_visited();

    BFS();

    return 0;
}