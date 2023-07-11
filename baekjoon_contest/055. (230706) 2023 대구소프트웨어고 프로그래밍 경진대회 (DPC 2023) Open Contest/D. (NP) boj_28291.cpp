// Solve 2023-07-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int graph[50][50];
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };

int main() {
    FASTIO;

    int w, h, n;
    cin >> w >> h >> n;

    int lamp_cnt = 0;
    queue<pii> que;

    for (int i = 0; i < n; i++) {
        string b;
        int x, y;
        cin >> b >> x >> y;

        if (b[9] == 'b') {
            que.emplace(x, y);
        }
        else if (b[9] == 'd') {
            graph[x][y] = 1;
        }
        else {
            graph[x][y] = 2;
            lamp_cnt++;
        }
    }

    for (int sig = 15; sig > 0; sig--) {
        int i_end = SIZE(que);

        for (int i = 0; i < i_end; i++) {
            pii xy = que.front();
            que.pop();

            for (int j = 0; j < 4; j++) {
                pii nxy = { xy.first + dx[j], xy.second + dy[j] };
                if (nxy.first < 0 || nxy.first >= w || nxy.second < 0 || nxy.second >= h) {
                    continue;
                }

                if (graph[nxy.first][nxy.second] == 1) {
                    graph[nxy.first][nxy.second] = 0;
                    que.push(nxy);
                }
                else if (graph[nxy.first][nxy.second] == 2) {
                    graph[nxy.first][nxy.second] = 0;
                    lamp_cnt--;
                }
            }
        }
    }

    if (lamp_cnt == 0) {
        cout << "success\n";
    }
    else {
        cout << "failed\n";
    }

    return 0;
}
