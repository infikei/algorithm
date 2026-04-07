// Solve 2026-03-22

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
    int to, dist;

    AdjNode(int to, int dist) : to(to), dist(dist) {
    }

    bool operator<(const AdjNode& rhs) const {
        return dist > rhs.dist;
    }
};

int n;
int a[2000];
int min_dist[2000];

void dijkstra() {
    priority_queue<AdjNode> pq;
    memset(min_dist, 0x3f, sizeof(min_dist));
    min_dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [cur, cur_dist] = pq.top();
        pq.pop();

        if (cur_dist > min_dist[cur]) continue;

        for (int i = 1; i < n; i++) {
            if (a[i] <= 0) continue;

            int nxt = (cur + i) % n;
            int nxt_dist = cur_dist + a[i];

            if (nxt_dist < min_dist[nxt]) {
                min_dist[nxt] = nxt_dist;
                pq.emplace(nxt, nxt_dist);
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    dijkstra();

    int q;
    cin >> q;

    while (q-- > 0) {
        int u, v;
        cin >> u >> v;
        int w = u - v;

        if (w < 0) w += n;

        cout << (min_dist[w] == INF ? -1 : min_dist[w]) << '\n';
    }

    return 0;
}
