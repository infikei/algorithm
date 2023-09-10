// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int graph[100][100][100];

int main() {
    FASTIO;

    int r, c, h;
    cin >> r >> c >> h;

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                char ch;
                cin >> ch;

                if (ch == '*') {
                    graph[z][x][y] = -999;

                    for (int dz = -1; dz <= 1; dz++) {
                        int nz = z + dz;
                        if (nz < 0 || nz >= h) continue;

                        for (int dx = -1; dx <= 1; dx++) {
                            int nx = x + dx;
                            if (nx < 0 || nx >= r) continue;

                            for (int dy = -1; dy <= 1; dy++) {
                                int ny = y + dy;
                                if (ny < 0 || ny >= c) continue;
                                if (z == nz && x == nx && y == ny) continue;
                                if (graph[nz][nx][ny] < 0) continue;

                                graph[nz][nx][ny]++;
                                if (graph[nz][nx][ny] >= 10) graph[nz][nx][ny] -= 10;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (graph[z][x][y] < 0) cout << '*';
                else cout << graph[z][x][y];
            }
            cout << '\n';
        }
    }

    return 0;
}
