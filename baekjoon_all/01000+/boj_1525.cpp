// Solve 2023-09-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    vector<string> initial_graph(3, "000");

    for (string &s : initial_graph) {
        for (char &c : s) {
            cin >> c;
        }
    }

    string target_str = "123456780";
    string initial_str = "";

    for (string &s : initial_graph) initial_str += s;

    unordered_set<string> hs;
    hs.insert(initial_str);

    queue<vector<string> > que;
    que.push(initial_graph);

    int ans = 0;

    if (initial_str != target_str) {
        int cnt = 0;

        while (!que.empty()) {
            cnt++;

            for (int que_i = 0, que_ie = SIZE(que); que_i < que_ie; que_i++) {
                vector<string> now_graph = que.front();
                que.pop();

                int x = 0, y = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (now_graph[i][j] == '0') {
                            x = i; y = j;
                        }
                    }
                }

                for (int d = 0; d < 4; d++) {
                    vector<string> next_graph = now_graph;

                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

                    swap(next_graph[x][y], next_graph[nx][ny]);

                    string next_str = "";

                    for (string &s : next_graph) next_str += s;

                    if (next_str == target_str) {
                        ans = cnt;
                        break;
                    }

                    if (hs.find(next_str) == hs.end()) {
                        hs.insert(next_str);
                        que.push(next_graph);
                    }
                }

                if (ans != 0) break;
            }

            if (ans != 0) break;
        }

        if (ans == 0) ans = -1;
    }

    cout << ans << '\n';

    return 0;
}
