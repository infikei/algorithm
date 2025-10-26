// Solve 2023-01-06
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

int dist[100001];
int memo[100001];

pii bfs(int n, int k) {
    if (n == k) return {0, 1};

    int a[3] = {1, 1, 2};
    int b[3] = {-1, 1, 0};

    memset(dist, 0x3f, sizeof dist);
    queue<int> que;
    que.push(n);
    dist[n] = 0;
    memo[n] = 1;

    while (!que.empty()) {
        int iter = size(que);

        while (iter-- > 0) {
            int cur = que.front();
            que.pop();

            for (int d = 0; d < 3; d++) {
                int nxt = cur * a[d] + b[d];

                if (nxt < 0 || nxt > 100000) continue;
                if (dist[cur] + 1 > dist[nxt]) continue;
                if (dist[cur] + 1 == dist[nxt]) {
                    memo[nxt] += memo[cur];
                    continue;
                }

                dist[nxt] = dist[cur] + 1;
                memo[nxt] = memo[cur];
                que.push(nxt);
            }
        }

        if (dist[k] != INF) {
            return {dist[k], memo[k]};
        }
    }

    return {-1, 0};
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    pii res = bfs(n, k);
    cout << res.first << '\n';
    cout << res.second << '\n';
    return 0;
}
