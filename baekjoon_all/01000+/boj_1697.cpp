// Solve 2022-10-01
// Update 2025-05-23

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool visited[100001];

int bfs(int n, int k) {
    if (n == k) return 0;

    queue<int> bfs_que;
    bfs_que.push(n);
    visited[n] = true;
    int dist = 0;

    while (!bfs_que.empty()) {
        dist++;
        int iter = bfs_que.size();

        while (iter-- > 0) {
            int cur = bfs_que.front();
            bfs_que.pop();

            if (cur * 2 <= 100000 && !visited[cur * 2]) {
                if (cur * 2 == k) return dist;

                visited[cur * 2] = true;
                bfs_que.push(cur * 2);
            }

            if (cur + 1 <= 100000 && !visited[cur + 1]) {
                if (cur + 1 == k) return dist;

                visited[cur + 1] = true;
                bfs_que.push(cur + 1);
            }

            if (cur >= 1 && !visited[cur - 1]) {
                if (cur - 1 == k) return dist;

                visited[cur - 1] = true;
                bfs_que.push(cur - 1);
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    cout << bfs(n, k) << '\n';

    return 0;
}
