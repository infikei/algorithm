#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R, cnt;
vector<int> graph[100001];
int visited[100001];

void input() {
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
}

void dfs(int now = R) {
    visited[now] = ++cnt;
    for (auto i : graph[now]) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
}

void print() {
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    dfs();

    print();

    return 0;
}