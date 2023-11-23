// Solve 2023-01-09
// Update 2023-11-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int main() {
    FASTIO;

    int tc;
    cin >> tc;

    for (int tci = 0; tci < tc; tci++) {
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;

        vector<vector<pii> > edges(n + 1, vector<pii>());

        for (int i = 0; i < m; i++) {
            int from, to, dist;
            cin >> from >> to >> dist;

            edges[from].emplace_back(to, dist);
            edges[to].emplace_back(from, dist);
        }

        vector<int> dists_from_s(n + 1, INF);
        priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
        dists_from_s[s] = 0;
        pq_mintop.emplace(0, s);

        while (!pq_mintop.empty()) {
            int now = pq_mintop.top().second;
            int dist_to_now = pq_mintop.top().first;
            pq_mintop.pop();

            if (dists_from_s[now] < dist_to_now) continue;

            for (pii edge : edges[now]) {
                int next = edge.first;
                int dist_to_next = dist_to_now + edge.second;

                if (dists_from_s[next] > dist_to_next) {
                    dists_from_s[next] = dist_to_next;
                    pq_mintop.emplace(dist_to_next, next);
                }
            }
        }

        int v2;

        if (dists_from_s[g] < dists_from_s[h]) {
            v2 = h;
        }
        else {
            v2 = g;
        }

        vector<int> dists_from_v2(n + 1, INF);
        dists_from_v2[v2] = 0;
        pq_mintop.emplace(0, v2);

        while (!pq_mintop.empty()) {
            int now = pq_mintop.top().second;
            int dist_to_now = pq_mintop.top().first;
            pq_mintop.pop();

            if (dists_from_v2[now] < dist_to_now) continue;

            for (pii edge : edges[now]) {
                int next = edge.first;
                int dist_to_next = dist_to_now + edge.second;

                if (dists_from_v2[next] > dist_to_next) {
                    dists_from_v2[next] = dist_to_next;
                    pq_mintop.emplace(dist_to_next, next);
                }
            }
        }

        vector<int> ans_vec;
        int dist_from_s_to_v2 = dists_from_s[v2];

        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;

            if (dist_from_s_to_v2 + dists_from_v2[x] == dists_from_s[x]) {
                ans_vec.push_back(x);
            }
        }

        sort(ans_vec.begin(), ans_vec.end());

        for (int ans : ans_vec) {
            cout << ans << ' ';
        }

        cout << '\n';
    }

    return 0;
}
