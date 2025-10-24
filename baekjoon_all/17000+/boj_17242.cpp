// Solve 2025-10-24

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

struct AdjNode{
    int to, w1, w2;

    AdjNode(int to, int w1, int w2) : to(to), w1(w1), w2(w2) {
    }
};

vector<AdjNode> adj[1000];
int memo[1000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    while (m-- > 0) {
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;
        adj[u].emplace_back(v, w1, w2);
        adj[v].emplace_back(u, w1, w2);
    }

    auto cmp = [](const AdjNode& a, const AdjNode& b) {
        if (a.w1 != b.w1) return a.w1 > b.w1;
        return a.w2 > b.w2;
    };

    priority_queue<AdjNode, vector<AdjNode>, decltype(cmp)> pq(cmp);
    memset(memo, 0x3f, sizeof memo);
    pq.emplace(0, 0, 0);
    int mn = INF;

    while (!pq.empty()) {
        AdjNode cur = pq.top();
        pq.pop();

        if (memo[cur.to] <= cur.w2) continue;
        if (cur.to == n - 1) {
            mn = min(mn, cur.w1 * cur.w2);
        }

        memo[cur.to] = cur.w2;

        for (AdjNode& nxt : adj[cur.to]) {
            int nw1 = cur.w1 + nxt.w1;
            int nw2 = cur.w2 + nxt.w2;

            if (nw1 <= 1000 && nw2 <= 1000 && memo[nxt.to] > nw2) {
                pq.emplace(nxt.to, nw1, nw2);
            }
        }
    }

    cout << (mn == INF ? -1 : mn) << '\n';
    return 0;
}
