// Solve 2023-04-11

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
using pii = pair<int, int>;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[100][100];

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    int ans = 0, ans2 = 0;
    stack<pii> stck;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (visited[row][col]) {
                continue;
            }

            visited[row][col] = true;
            stck.push({ row, col });
            ans++;
            char ch = graph[row][col];

            while (!stck.empty()) {
                pii cur = stck.top();
                stck.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = cur.first + dx[i];
                    int ncol = cur.second + dy[i];
                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) {
                        continue;
                    }
                    if (visited[nrow][ncol] || graph[nrow][ncol] != ch) {
                        continue;
                    }
                    visited[nrow][ncol] = true;
                    stck.push({ nrow, ncol });
                }
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            visited[row][col] = false;
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (visited[row][col]) {
                continue;
            }

            visited[row][col] = true;
            stck.push({ row, col });
            ans2++;
            char ch = graph[row][col];
            if (ch == 'G') {
                ch = 'R';
            }

            while (!stck.empty()) {
                pii cur = stck.top();
                stck.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = cur.first + dx[i];
                    int ncol = cur.second + dy[i];
                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) {
                        continue;
                    }
                    char ch2 = graph[nrow][ncol];
                    if (ch2 == 'G') {
                        ch2 = 'R';
                    }
                    if (visited[nrow][ncol] || ch2 != ch) {
                        continue;
                    }
                    visited[nrow][ncol] = true;
                    stck.push({ nrow, ncol });
                }
            }
        }
    }

    cout << ans << ' ' << ans2 << '\n';

    return 0;
}
