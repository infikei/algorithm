// Solve 2022-10-01
// Update 2023-02-10

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 100000;
int n, k, ans;
queue<int> q;
bool visited[MAX_N + 1];

void bfs() {
    if (n == k) return;

    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        ans++;

        int i_end = SIZE(q);
        for (int i = 0; i < i_end; i++) {
            int cur = q.front();
            q.pop();

            int next;

            next = cur * 2;
            if (next == k) return;
            if (next <= MAX_N && !visited[next]) {
                visited[next] = true;
                q.push(next);
            }

            next = cur + 1;
            if (next == k) return;
            if (next <= MAX_N && !visited[next]) {
                visited[next] = true;
                q.push(next);
            }

            next = cur - 1;
            if (next == k) return;
            if (next >= 0 && !visited[next]) {
                visited[next] = true;
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

    return 0;
}