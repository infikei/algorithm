// Solve 2024-10-27

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

bool visited[501];
vector<int> adj[501];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u1, u2;
        cin >> u1 >> u2;

        adj[u1].push_back(u2);
        adj[u2].push_back(u1);
    }

    int ans = 0;
    queue<int> bfs_que;
    visited[1] = true;
    bfs_que.push(1);

    for (int i = 0; i < 2; i++) {
        int iter = size(bfs_que);

        while (iter-- > 0) {
            int cur = bfs_que.front();
            bfs_que.pop();

            for (int nxt : adj[cur]) {
                if (visited[nxt]) continue;

                visited[nxt] = true;
                bfs_que.push(nxt);
                ans++;
            }
        }
    }

    println(ans);

    return 0;
}
