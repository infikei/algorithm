// Solve 2025-09-10

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Point{
    int a, b, c, d, e, f, g, h, i, j, k;

    Point(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j), k(k) {
    }
};

int da[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int db[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0};
int dc[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0};
int dd[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0};
int de[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
int df[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dg[22] = {0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dh[22] = {0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int di[22] = {0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dj[22] = {0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dk[22] = {-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
    FASTIO;

    int m, n, o, p, q, r, s, t, u, v, w;
    cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
    int*********** board = new int**********[w];
    queue<Point> bfs_que;
    int not_ripe_cnt = 0;

    for (int a = 0; a < w; a++) {
        board[a] = new int*********[v];

        for (int b = 0; b < v; b++) {
            board[a][b] = new int********[u];

            for (int c = 0; c < u; c++) {
                board[a][b][c] = new int*******[t];

                for (int d = 0; d < t; d++) {
                    board[a][b][c][d] = new int******[s];

                    for (int e = 0; e < s; e++) {
                        board[a][b][c][d][e] = new int*****[r];

                        for (int f = 0; f < r; f++) {
                            board[a][b][c][d][e][f] = new int****[q];

                            for (int g = 0; g < q; g++) {
                                board[a][b][c][d][e][f][g] = new int***[p];

                                for (int h = 0; h < p; h++) {
                                    board[a][b][c][d][e][f][g][h] = new int**[o];

                                    for (int i = 0; i < o; i++) {
                                        board[a][b][c][d][e][f][g][h][i] = new int*[n];

                                        for (int j = 0; j < n; j++) {
                                            board[a][b][c][d][e][f][g][h][i][j] = new int[m];

                                            for (int k = 0; k < m; k++) {
                                                int val;
                                                cin >> val;
                                                board[a][b][c][d][e][f][g][h][i][j][k] = val;

                                                if (val == 0) {
                                                    not_ripe_cnt++;
                                                }
                                                else if (val == 1) {
                                                    bfs_que.emplace(a, b, c, d, e, f, g, h, i, j, k);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int cur_day = 0;

    while (not_ripe_cnt > 0 && !bfs_que.empty()) {
        cur_day++;
        int iter = size(bfs_que);

        while (iter-- > 0) {
            Point cur = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 22; d++) {
                int na = cur.a + da[d];
                int nb = cur.b + db[d];
                int nc = cur.c + dc[d];
                int nd = cur.d + dd[d];
                int ne = cur.e + de[d];
                int nf = cur.f + df[d];
                int ng = cur.g + dg[d];
                int nh = cur.h + dh[d];
                int ni = cur.i + di[d];
                int nj = cur.j + dj[d];
                int nk = cur.k + dk[d];

                if (na < 0 || na >= w) continue;
                if (nb < 0 || nb >= v) continue;
                if (nc < 0 || nc >= u) continue;
                if (nd < 0 || nd >= t) continue;
                if (ne < 0 || ne >= s) continue;
                if (nf < 0 || nf >= r) continue;
                if (ng < 0 || ng >= q) continue;
                if (nh < 0 || nh >= p) continue;
                if (ni < 0 || ni >= o) continue;
                if (nj < 0 || nj >= n) continue;
                if (nk < 0 || nk >= m) continue;

                if (board[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk] == 0) {
                    board[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk] = 1;
                    bfs_que.emplace(na, nb, nc, nd, ne, nf, ng, nh, ni, nj, nk);
                    not_ripe_cnt--;
                }
            }
        }
    }

    cout << (not_ripe_cnt > 0 ? -1 : cur_day) << '\n';

    for (int a = 0; a < w; a++) {
        for (int b = 0; b < v; b++) {
            for (int c = 0; c < u; c++) {
                for (int d = 0; d < t; d++) {
                    for (int e = 0; e < s; e++) {
                        for (int f = 0; f < r; f++) {
                            for (int g = 0; g < q; g++) {
                                for (int h = 0; h < p; h++) {
                                    for (int i = 0; i < o; i++) {
                                        for (int j = 0; j < n; j++) {
                                            delete[] board[a][b][c][d][e][f][g][h][i][j];
                                        }

                                        delete[] board[a][b][c][d][e][f][g][h][i];
                                    }

                                    delete[] board[a][b][c][d][e][f][g][h];
                                }

                                delete[] board[a][b][c][d][e][f][g];
                            }

                            delete[] board[a][b][c][d][e][f];
                        }

                        delete[] board[a][b][c][d][e];
                    }

                    delete[] board[a][b][c][d];
                }

                delete[] board[a][b][c];
            }

            delete[] board[a][b];
        }

        delete[] board[a];
    }

    delete[] board;
    board = nullptr;
    return 0;
}
