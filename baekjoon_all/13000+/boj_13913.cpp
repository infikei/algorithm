// Solve 2023-02-11
// Update 2023-03-24

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

const int MAX_N = 100000;
int n, k, ans, parent[MAX_N + 1];
bool visited[MAX_N + 1];

void bfs() {
    parent[n] = -1;
    if (n == k) return;

    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        ans++;

        int i_end = SIZE(q);
        for (int i = 0; i < i_end; i++) {
            int now = q.front();
            q.pop();

            int next;

            next = now * 2;
            if (next <= MAX_N && !visited[next]) {
                visited[next] = true;
                parent[next] = now;
                if (next == k) return;
                q.push(next);
            }

            next = now + 1;
            if (next <= MAX_N && !visited[next]) {
                visited[next] = true;
                parent[next] = now;
                if (next == k) return;
                q.push(next);
            }

            next = now - 1;
            if (next >= 0 && !visited[next]) {
                visited[next] = true;
                parent[next] = now;
                if (next == k) return;
                q.push(next);
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> k;

    bfs();

    cout << ans << '\n';

    stack<int> path;
    int cur = k;
    while (cur != -1) {
        path.push(cur);
        cur = parent[cur];
    }
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';

    return 0;
}
