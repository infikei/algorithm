// Solve 2023-02-11
// Update 2025-10-26

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

bool visited[100001];
int parent[100001];

int bfs(int n, int k) {
    if (n == k) return 0;

    int a[3] = {1, 1, 2};
    int b[3] = {-1, 1, 0};

    queue<int> que;
    que.push(n);
    visited[n] = true;
    int dist = 0;

    while (!que.empty()) {
        dist++;
        int iter = size(que);

        while (iter-- > 0) {
            int cur = que.front();
            que.pop();

            for (int d = 0; d < 3; d++) {
                int nxt = cur * a[d] + b[d];

                if (nxt < 0 || nxt > 100000 || visited[nxt]) continue;

                visited[nxt] = true;
                parent[nxt] = cur;
                que.push(nxt);

                if (nxt == k) return dist;
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    int ans = bfs(n, k);
    stack<int> path;
    path.push(k);
    int cur = k;

    for (int i = 0; i < ans; i++) {
        cur = parent[cur];
        path.push(cur);
    }

    cout << ans << '\n';

    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }

    cout << '\n';
    return 0;
}
