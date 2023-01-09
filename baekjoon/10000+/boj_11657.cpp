#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 2100000000;
const int MAX_N = 500;
int n, m;
vector<pair<pii, int> > edge;
ll dist[MAX_N + 1];
bool exist_cycle;

void bellman_ford(int start = 1) {
    exist_cycle = false;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[start] = 0;

    int edge_size = edge.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < edge_size; j++) {
            int from = edge[j].first.first;
            int to = edge[j].first.second;
            ll cost = edge[j].second;

            if (dist[from] == INF) continue;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    for (int j = 0; j < edge_size; j++) {
        int from = edge[j].first.first;
        int to = edge[j].first.second;
        ll cost = edge[j].second;

        if (dist[from] == INF) continue;
        if (dist[to] > dist[from] + cost) {
            exist_cycle = true;
            return;
        }
    }
}

void input() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge.push_back(make_pair(make_pair(from, to), cost));
    }
}

int main() {
    fastio;

    input();

    bellman_ford();

    if (exist_cycle) cout << -1 << '\n';
    else {
        for (int i = 2; i <= n; i++) {
            cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
        }
    }

    return 0;
}