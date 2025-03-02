// Solve 2023-05-23
// Update 2025-03-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Fireball{
    int m, s, d, cnt;

    Fireball(int _m = 0, int _s = 0, int _d = 0, int _cnt = 0) : m(_m), s(_s), d(_d), cnt(_cnt) {
    }

    Fireball operator+(const Fireball &rhs) const {
        if (cnt + rhs.cnt > 1) {
            int new_d = d;

            if (d == -1 || new_d == -1 || (d & 1) != (rhs.d & 1)) {
                new_d = -1;
            }

            return { m + rhs.m, s + rhs.s, new_d, cnt + rhs.cnt };
        }

        if (rhs.cnt == 1) {
            return rhs;
        }

        return { m, s, d, cnt };
    }

    Fireball& operator+=(const Fireball &rhs) {
        (*this) = (*this) + rhs;
        return *this;
    }
};

int n, m, k;
vector<vector<Fireball>> graph, new_graph;
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
    FASTIO;

    cin >> n >> m >> k;
    graph.assign(n, vector<Fireball>(n, Fireball()));

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        cin >> graph[r][c].m >> graph[r][c].s >> graph[r][c].d;
        graph[r][c].cnt = 1;
    }

    for (int ki = 0; ki < k; ki++) {
        new_graph.assign(n, vector<Fireball>(n, Fireball()));

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (graph[x][y].cnt >= 2) {
                    int new_m = graph[x][y].m / 5;

                    if (new_m == 0) continue;

                    int new_s = graph[x][y].s / graph[x][y].cnt;
                    int new_d = 0;

                    if (graph[x][y].d == -1) new_d = 1;

                    for (; new_d < 8; new_d += 2) {
                        int new_x = (x + (dr[new_d] + n) * new_s) % n;
                        int new_y = (y + (dc[new_d] + n) * new_s) % n;
                        new_graph[new_x][new_y] += Fireball(new_m, new_s, new_d, 1);
                    }
                }
                if (graph[x][y].cnt == 1) {
                    int new_x = (x + (dr[graph[x][y].d] + n) * graph[x][y].s) % n;
                    int new_y = (y + (dc[graph[x][y].d] + n) * graph[x][y].s) % n;
                    new_graph[new_x][new_y] += graph[x][y];
                }
            }
        }

        graph = new_graph;
    }

    int ans = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (graph[x][y].cnt >= 2) {
                ans += graph[x][y].m / 5 << 2;
            }
            else if (graph[x][y].cnt == 1) {
                ans += graph[x][y].m;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
