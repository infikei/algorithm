// Solve 2022-07-24
// Update 2023-03-20

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

bool graph[1001][1001] = { false };
bool visited[1001] = { false };
int n, v;

void dfs() {
    stack<int> stck;
    stck.push(v);

    while (!stck.empty()) {
        int now = stck.top();
        stck.pop();
        if (!visited[now]) {
            visited[now] = true;
            cout << now << ' ';

            // n부터 1까지 검사하며 추가
            for (int next = n; next >= 1; next--) {
                if (!visited[next] && graph[now][next]) {
                    stck.push(next);
                }
            }
        }
    }

    cout << '\n';
}

void bfs() {
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (!visited[now]) {
            visited[now] = true;
            cout << now << ' ';

            // 1부터 n까지 검사하며 추가
            for (int next = 1; next <= n; next++) {
                if (!visited[next] && graph[now][next]) {
                    q.push(next);
                }
            }
        }
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int m;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = true;
        graph[to][from] = true;
    }

    dfs();

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    bfs();

    return 0;
}
