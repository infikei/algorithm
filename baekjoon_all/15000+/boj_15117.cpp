// Solve 2025-04-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

string solution() {
    int n;
    cin >> n;

    vector<string> board(n);

    for (string &row : board) {
        cin >> row;
    }

    for (int x = 0; x < n; x++) {
        vector<bool> row_check(n, false);

        for (int y = 0; y < n; y++) {
            int d = (board[x][y] >= 'A' ? board[x][y] - 'A' + 10 : board[x][y] - '0');

            if (row_check[d]) {
                return "No";
            }

            row_check[d] = true;
        }
    }

    for (int y = 0; y < n; y++) {
        vector<bool> col_check(n, false);

        for (int x = 0; x < n; x++) {
            int d = (board[x][y] >= 'A' ? board[x][y] - 'A' + 10 : board[x][y] - '0');

            if (col_check[d]) {
                return "No";
            }

            col_check[d] = true;
        }
    }

    for (int i = 1; i < n; i++) {
        if (board[0][i - 1] >= board[0][i]) {
            return "Not Reduced";
        }

        if (board[i - 1][0] >= board[i][0]) {
            return "Not Reduced";
        }
    }

    return "Reduced";
}

int main() {
    FASTIO;

    cout << solution() << '\n';

    return 0;
}
