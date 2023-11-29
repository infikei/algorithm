// Solve 2023-11-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e12;

struct Hole{
    int x, y, t;

    Hole(int x = 0, int y = 0, int t = 0) : x(x), y(y), t(t) {}
};

int main() {
    FASTIO;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    while (true) {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0) break;

        vector<vector<int>> board(w, vector<int>(h, 0));

        int g;
        cin >> g;

        for (int i = 0; i < g; i++) {
            int x, y;
            cin >> x >> y;

            board[x][y] = -1;
        }

        vector<vector<Hole>> hole(w, vector<Hole>(h));

        int e;
        cin >> e;

        for (int i = 0; i < e; i++) {
            int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;

            board[x1][y1] = 1;
            hole[x1][y1] = Hole(x2, y2, t);
        }

        // 벨만-포드

        vector<vector<ll>> time(w, vector<ll>(h, INF));
        time[0][0] = 0;
        int iter = w * h - 1;

        while (iter > 0) {
            iter--;

            for (int x = 0; x < w; x++) {
                for (int y = 0; y < h; y++) {
                    if (time[x][y] == INF) continue;
                    if (x == w - 1 && y == h - 1) continue;

                    if (board[x][y] == 1) {
                        int nx = hole[x][y].x;
                        int ny = hole[x][y].y;
                        ll ntime = time[x][y] + hole[x][y].t;

                        if (time[nx][ny] > ntime) {
                            time[nx][ny] = ntime;
                        }
                    }
                    else if (board[x][y] == 0) {
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                            if (board[nx][ny] == -1) continue;

                            ll ntime = time[x][y] + 1;

                            if (time[nx][ny] > ntime) {
                                time[nx][ny] = ntime;
                            }
                        }
                    }
                }
            }
        }

        bool flag_has_negative_cycle = false;

        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                if (time[x][y] == INF) continue;
                if (x == w - 1 && y == h - 1) continue;

                if (board[x][y] == 1) {
                    int nx = hole[x][y].x;
                    int ny = hole[x][y].y;
                    ll ntime = time[x][y] + hole[x][y].t;

                    if (time[nx][ny] > ntime) {
                        flag_has_negative_cycle = true;
                    }
                }
                else if (board[x][y] == 0) {
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                        if (board[nx][ny] == -1) continue;

                        ll ntime = time[x][y] + 1;

                        if (time[nx][ny] > ntime) {
                            flag_has_negative_cycle = true;
                            break;
                        }
                    }
                }

                if (flag_has_negative_cycle) break;
            }

            if (flag_has_negative_cycle) break;
        }

        if (flag_has_negative_cycle) {
            cout << "Never\n";
        }
        else if (time[w - 1][h - 1] == INF) {
            cout << "Impossible\n";
        }
        else {
            cout << time[w - 1][h - 1] << '\n';
        }
    }

    return 0;
}
