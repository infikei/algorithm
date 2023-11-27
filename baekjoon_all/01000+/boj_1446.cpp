// Solve 2023-11-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n, d;
    cin >> n >> d;

    vector<vector<pii>> shortcuts(d + 1, vector<pii>());

    for (int i = 0; i < n; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;

        if (to <= d && dist < to - from) {
            shortcuts[to].emplace_back(from, dist);
        }
    }

    vector<int> dist(d + 1);

    for (int u = 1; u <= d; u++) {
        dist[u] = dist[u - 1] + 1;

        for (pii shortcut : shortcuts[u]) {
            dist[u] = min(dist[u], dist[shortcut.first] + shortcut.second);
        }
    }

    cout << dist[d] << '\n';

    return 0;
}
