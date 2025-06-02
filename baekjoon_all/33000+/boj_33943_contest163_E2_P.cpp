// Solve 2025-05-31

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

int p[2000];
bool visited[20001];

int bfs(int n, int m) {
    if (m == 0) return 0;

    queue<int> bfs_que;
    bfs_que.push(0);
    visited[10000] = 0;
    int dist = 0;

    while (!bfs_que.empty()) {
        dist++;
        int iter = bfs_que.size();

        while (iter-- > 0) {
            int cur = bfs_que.front();
            bfs_que.pop();

            for (int i = 0; i < n; i++) {
                int nxt = cur + p[i];

                if (nxt < -10000 || nxt > 10000 || visited[nxt + 10000]) continue;
                if (nxt == m) return dist;

                visited[nxt + 10000] = true;
                bfs_que.push(nxt);
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << bfs(n, m) << '\n';

    return 0;
}
