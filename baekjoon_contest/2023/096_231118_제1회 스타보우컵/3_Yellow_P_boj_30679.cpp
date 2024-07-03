// Solve 2023-11-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dr[4] = { 0, 1, 0, -1 };
    int dc[4] = { 1, 0, -1, 0 };

    int n, m;
    cin >> n >> m;

    vector<vector<int> > board(n, vector<int>(m, 0));

    for (vector<int> &vec : board) {
        for (int &x : vec) {
            cin >> x;
        }
    }

    vector<int> ans;

    for (int r0 = 0; r0 < n; r0++) {
        vector<vector<vector<bool> > > visited(n, vector<vector<bool> >(m, vector<bool>(4, false)));
        int r = r0;
        int c = 0;
        int d = 0;
        visited[r][c][d] = true;

        while (true) {
            int val = board[r][c];
            r += dr[d] * val;
            c += dc[d] * val;
            if (++d == 4) d = 0;

            if (r < 0 || r >= n || c < 0 || c >= m) break;
            if (visited[r][c][d]) {
                ans.push_back(r0);
                break;
            }

            visited[r][c][d] = true;
        }
    }

    cout << SIZE(ans) << '\n';

    if (!ans.empty()) {
        for (int &x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
