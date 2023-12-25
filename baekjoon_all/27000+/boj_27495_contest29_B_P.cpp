// Solve 2023-02-19
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

    vector<vector<string>> board(9, vector<string>(9));

    for (vector<string> &vec : board) {
        for (string &s : vec) {
            cin >> s;
        }
    }

    vector<pair<string, vector<string>>> goals;
    int idx = 0;

    for (int row3 = 0; row3 < 9; row3 += 3) {
        for (int col3 = 0; col3 < 9; col3 += 3) {
            if (row3 == 3 && col3 == 3) continue;

            pair<string, vector<string>> cur_goal;
            cur_goal.first = board[row3 + 1][col3 + 1];

            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (row == 1 && col == 1) continue;

                    cur_goal.second.push_back(board[row3 + row][col3 + col]);
                }
            }

            sort(cur_goal.second.begin(), cur_goal.second.end());
            goals.push_back(cur_goal);
            idx++;
        }
    }

    sort(goals.begin(), goals.end());

    for (int i = 0; i < 8; i++) {
        cout << '#' << i + 1 << ". " << goals[i].first << '\n';

        for (int j = 0; j < 8; j++) {
            cout << '#' << i + 1 << '-' << j + 1 << ". " << goals[i].second[j] << '\n';
        }
    }

    return 0;
}
