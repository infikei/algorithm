// Solve 2023-02-19

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
using pii = pair<int, int>;
using pi3 = pair<int, pii>;

const int MAX_V = 10000;
int v, e;
priority_queue<pi3, vector<pi3>, greater<pi3> > edges;
int parent[MAX_V + 1];

int get_parent(int k) {
    if (parent[k] < 0) {
        return k;
    }

    parent[k] = get_parent(parent[k]);
    return parent[k];
}

int main() {
    FASTIO;

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push({ c, { a, b } });
    }
    for (int i = 1; i <= v; i++) {
        parent[i] = -1;
    }

    int ans = 0;
    while (!edges.empty()) {
        auto edge = edges.top();
        edges.pop();

        int pa = get_parent(edge.second.first);
        int pb = get_parent(edge.second.second);

        if (pa != pb) {
            ans += edge.first;
            if (parent[pa] < parent[pb]) {
                parent[pa] += parent[pb];
                parent[pb] = pa;
            }
            else {
                parent[pb] += parent[pa];
                parent[pa] = pb;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}