// Solve 2023-09-16
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int i, n, k;
    string colors;
    cin >> i >> n >> k >> colors;

    vector<string> graph(n);
    int pos_r = 0;
    int pos_c = 0;

    for (int row = 0; row < n; row++) {
        cin >> graph[row];

        for (int col = 0; col < n; col++) {
            if (graph[row][col] == '@') {
                pos_r = row;
                pos_c = col;
            }
        }
    }

    string cmds;
    cin >> cmds;

    int ink_m = 0;
    int ink_c = -1;

    for (char cmd : cmds) {
        if (cmd == 'U') {
            if (pos_r >= 1 && graph[pos_r - 1][pos_c] == '.') {
                swap(graph[pos_r - 1][pos_c], graph[pos_r][pos_c]);
                pos_r--;
            }
        }
        else if (cmd == 'D') {
            if (pos_r + 1 < n && graph[pos_r + 1][pos_c] == '.') {
                swap(graph[pos_r + 1][pos_c], graph[pos_r][pos_c]);
                pos_r++;
            }
        }
        else if (cmd == 'L') {
            if (pos_c >= 1 && graph[pos_r][pos_c - 1] == '.') {
                swap(graph[pos_r][pos_c - 1], graph[pos_r][pos_c]);
                pos_c--;
            }
        }
        else if (cmd == 'R') {
            if (pos_c + 1 < n && graph[pos_r][pos_c + 1] == '.') {
                swap(graph[pos_r][pos_c + 1], graph[pos_r][pos_c]);
                pos_c++;
            }
        }
        else if (cmd == 'j') {
            ink_m++;
        }
        else if (cmd == 'J') {
            if (++ink_c >= i) ink_c = 0;

            char color = colors[ink_c];

            for (int row = pos_r - ink_m, row_end = pos_r + ink_m; row <= row_end; row++) {
                if (row < 0 || row >= n) continue;

                int ink_m2 = ink_m - abs(row - pos_r);

                for (int col = pos_c - ink_m2, col_end = pos_c + ink_m2; col <= col_end; col++) {
                    if (col < 0 || col >= n || graph[row][col] == '.' || graph[row][col] == '@') continue;

                    graph[row][col] = color;
                }
            }

            ink_m = 0;
        }
    }

    for (string &line : graph) {
        cout << line << '\n';
    }

    return 0;
}
