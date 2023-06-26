// Solve 2023-06-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string graph[3];
        for (int row = 0; row < 3; row++) {
            cin >> graph[row];
        }

        vector<int> vec;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (graph[row][col] != 'O') continue;

                vec.push_back(0);
                queue<pii> que;
                que.push({ row, col });
                graph[row][col] = '#';

                while (!que.empty()) {
                    pii cur = que.front();
                    que.pop();
                    vec.back()++;

                    for (int i = 0; i < 4; i++) {
                        pii next = { cur.first + dx[i], cur.second + dy[i] };
                        if (next.first < 0 || next.first > 2) continue;
                        if (next.second < 0 || next.second > 2) continue;
                        if (graph[next.first][next.second] != 'O') continue;

                        que.push(next);
                        graph[next.first][next.second] = '#';
                    }
                }
            }
        }

        sort(vec.begin(), vec.end());
        int ans = 1;

        int n;
        cin >> n;
        if (n != SIZE(vec)) ans = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (ans && x != vec[i]) ans = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}
