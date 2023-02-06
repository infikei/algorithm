#include <iostream>
#include <vector>
#include <stack>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

int n, m, ans, map[8][8];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int dfs(const vector<pii> &v) {
    int res = 0;
    int dfs_map[8][8];
    bool dfs_visited[8][8] = {false};

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            dfs_map[row][col] = map[row][col];
        }
    }
    for (auto a : v) {
        dfs_map[a.first][a.second] = 1;
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (dfs_visited[row][col]) continue;
            dfs_visited[row][col] = true;
            if (dfs_map[row][col] == 1) continue;

            stack<pii> stck;
            stck.push({row, col});
            bool detect_virus = (dfs_map[row][col] == 2 ? true : false);
            int area_cnt = 1;

            while (!stck.empty()) {
                pii now = stck.top();
                stck.pop();
                for (int i = 0; i < 4; i++) {
                    pii next = {now.first + dx[i], now.second + dy[i]};
                    if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
                    if (dfs_visited[next.first][next.second]) continue;
                    dfs_visited[next.first][next.second] = true;
                    if (dfs_map[next.first][next.second] == 1) continue;
                    if (dfs_map[next.first][next.second] == 2) detect_virus = true;
                    area_cnt++;
                    stck.push(next);
                }
            }

            if (!detect_virus) res += area_cnt;
        }
    }

    return res;
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> map[row][col];
        }
    }

    int nm = n * m;
    vector<pii> v;
    for (int i = 0; i < nm; i++) {
        if (map[i / m][i % m] != 0) continue;
        v.push_back({i / m, i % m});
        for (int j = i + 1; j < nm; j++) {
            if (map[j / m][j % m] != 0) continue;
            v.push_back({j / m, j % m});
            for (int k = j + 1; k < nm; k++) {
                if (map[k / m][k % m] != 0) continue;
                v.push_back({k / m, k % m});
                ans = max(ans, dfs(v));
                v.pop_back();
            }
            v.pop_back();
        }
        v.pop_back();
    }

    cout << ans << '\n';

    return 0;
}