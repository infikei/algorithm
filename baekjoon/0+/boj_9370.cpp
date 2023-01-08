#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int INF = 987654321, MAX_N = 2000;
int n, m, t, s, g, h;
vector<pii> edge[MAX_N + 1];
int dist[MAX_N + 1];
vector<int> destination, s_to_destination, ans;

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq_mintop.push(make_pair(0, start));

    while (!pq_mintop.empty()) {
        int now_node = pq_mintop.top().second;
        int now_dist = pq_mintop.top().first;
        pq_mintop.pop();

        int i_end = edge[now_node].size();
        for (int i = 0; i < i_end; i++) {
            int next_node = edge[now_node][i].first;
            int next_dist = edge[now_node][i].second;

            if (dist[next_node] > now_dist + next_dist) {
                dist[next_node] = now_dist + next_dist;
                pq_mintop.push(make_pair(dist[next_node], next_node));
            }
        }
    }
}

int main() {
    fastio;

    int tc;
    cin >> tc;

    for (int tci = 0; tci < tc; tci++) {
        cin >> n >> m >> t >> s >> g >> h;

        for (int i = 1; i <= n; i++) edge[i].clear();
        destination.clear();
        s_to_destination.clear();
        ans.clear();

        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            edge[a].push_back(make_pair(b, d));
            edge[b].push_back(make_pair(a, d));
        }
        
        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;
            destination.push_back(x);
        }

        dijkstra(s);
        if (dist[g] > dist[h]) {
            int tmp = g;
            g = h;
            h = tmp;
        }
        int s_to_h = dist[h];
        for (int i = 0; i < t; i++) {
            s_to_destination.push_back(dist[destination[i]]);
        }

        dijkstra(h);
        for (int i = 0; i < t; i++) {
            if (s_to_destination[i] == s_to_h + dist[destination[i]]) {
                ans.push_back(destination[i]);
            }
        }
        sort(ans.begin(), ans.end());
        for (auto a : ans) cout << a << ' ';
        cout << '\n';
    }

    return 0;
}