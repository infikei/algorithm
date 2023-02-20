// Solve 2023-02-20

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pi3 = pair<int, pii>;

const int MAX_M = 200000; 
int m, n;
priority_queue<pi3, vector<pi3>, greater<pi3> > edges;
int parent[MAX_M];

int get_parent(int k) {
    if (parent[k] < 0) {
        return k;
    }

    parent[k] = get_parent(parent[k]);
    return parent[k];
}

int main() {
    FASTIO;

    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        for (int i = 0; i < m; i++) {
            parent[i] = -1;
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int from, to, dist;
            cin >> from >> to >> dist;

            ans += dist;
            edges.push({ dist, { from, to } });
        }

        while (!edges.empty()) {
            auto edge = edges.top();
            edges.pop();

            int pu = get_parent(edge.second.first);
            int pv = get_parent(edge.second.second);

            if (pu != pv) {
                ans -= edge.first;
                if (parent[pu] < parent[pv]) {
                    parent[pu] += parent[pv];
                    parent[pv] = pu;
                }
                else {
                    parent[pv] += parent[pu];
                    parent[pu] = pv;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}