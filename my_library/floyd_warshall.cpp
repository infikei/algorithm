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
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int INF = 1e9;
const ll LLINF = 4e18;
int vertex, edge;
vector<vector<int> > costs;

void floyd_warshall() {
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            for (int k = 0; k < vertex; k++) {
                if (costs[j][i] != INF && costs[i][k] != INF) {
                    costs[j][k] = min(costs[j][k], costs[j][i] + costs[i][k]);
                }
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> vertex >> edge;
    costs.assign(vertex, vector<int>(vertex, INF));
    for (int i = 0; i < vertex; i++) costs[i][i] = 0;
    for (int i = 0; i < edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        costs[from][to] = min(costs[from][to], cost);
        costs[to][from] = min(costs[to][from], cost); // 양방향일 경우
    }

    floyd_warshall();

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << (costs[i][j] == INF ? 0 : costs[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}