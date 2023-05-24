// Solve 2023-05-23

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

struct Fireball{
    int m, s, d, cnt;
    Fireball(int _m = 0, int _s = 0, int _d = 0, int _cnt = 0) : m(_m), s(_s), d(_d), cnt(_cnt) {}
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
vector<vector<Fireball> > graph, new_graph;
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

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (graph[r][c].cnt >= 2) {
                    int new_m = graph[r][c].m / 5;
                    if (new_m == 0) continue;
                    int new_s = graph[r][c].s / graph[r][c].cnt;
                    int new_d = 0;
                    if (graph[r][c].d == -1) new_d = 1;

                    for (; new_d < 8; new_d += 2) {
                        int new_r = (r + (dr[new_d] + n) * new_s) % n;
                        int new_c = (c + (dc[new_d] + n) * new_s) % n;
                        new_graph[new_r][new_c] += Fireball(new_m, new_s, new_d, 1);
                    }
                }
                if (graph[r][c].cnt == 1) {
                    int new_r = (r + (dr[graph[r][c].d] + n) * graph[r][c].s) % n;
                    int new_c = (c + (dc[graph[r][c].d] + n) * graph[r][c].s) % n;
                    new_graph[new_r][new_c] += graph[r][c];
                }
            }
        }

        graph = new_graph;
    }

    int ans = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (graph[r][c].cnt >= 2) {
                ans += graph[r][c].m / 5 << 2;
            }
            else if (graph[r][c].cnt == 1) {
                ans += graph[r][c].m;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
