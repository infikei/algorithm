// Solve 2025-05-11

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

int dx[5] = { -2, -1, -1, 0, 0 };
int dy[5] = { 0, -1, 1, -2, 2 };

int main() {
    FASTIO;

    string s;
    cin >> s;

    int m = s.size() * 4 + 1;
    vector<string> board(3, string(m, '.'));

    for (int i = 0; i < s.size(); i++) {
        board[2][i * 4 + 2] = s[i];

        for (int d = 0; d < 5; d++) {
            board[2 + dx[d]][i * 4 + 2 + dy[d]] = '#';
        }
    }

    for (int i = 2; i < s.size(); i += 3) {
        for (int d = 0; d < 5; d++) {
            board[2 + dx[d]][i * 4 + 2 + dy[d]] = '*';
        }
    }

    cout << board[0] << '\n';
    cout << board[1] << '\n';
    cout << board[2] << '\n';
    cout << board[1] << '\n';
    cout << board[0] << '\n';

    return 0;
}
