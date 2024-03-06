// Solve 2024-03-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int adj[1001][1001];
int team[1001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (true) {
        int from, to;
        cin >> from >> to;

        if (from == -1 && to == -1) break;

        adj[from][to] = 1;
        adj[to][from] = 1;
    }

    for (int u = 1; u <= n; u++) {
        adj[u][u] = 1;
    }

    bool valid = true;
    queue<int> que;
    que.push(1);
    team[1] = 1;
    int iter = n;
    int u1s = 2;

    while (iter-- > 0) {
        while (team[u1s] != 0) {
            u1s++;
        }

        int u1;

        if (que.empty()) {
            u1 = u1s++;
            team[u1] = 1;
        }
        else {
            u1 = que.front();
            que.pop();
        }

        int team_u2 = 3 - team[u1];

        for (int u2 = 1; u2 <= n; u2++) {
            if (adj[u1][u2] == 0) {
                if (team[u2] == 0) {
                    team[u2] = team_u2;
                    que.push(u2);
                }
                else if (team[u2] != team_u2) {
                    valid = false;
                    break;
                }
            }
        }

        if (!valid) break;
    }

    if (valid) {
        cout << 1 << '\n';

        for (int u = 1; u <= n; u++) {
            if (team[u] == 1) {
                cout << u << ' ';
            }
        }

        cout << -1 << '\n';

        for (int u = 1; u <= n; u++) {
            if (team[u] == 2) {
                cout << u << ' ';
            }
        }

        cout << -1 << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
