// Solve 2025-06-19

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int sudoku[9][9];
bool visited[10];

bool check_row(int x) {
    memset(visited, 0, sizeof visited);

    for (int y = 0; y < 9; y++) {
        if (visited[sudoku[x][y]]) return false;

        visited[sudoku[x][y]] = true;
    }

    return true;
}

bool check_col(int y) {
    memset(visited, 0, sizeof visited);

    for (int x = 0; x < 9; x++) {
        if (visited[sudoku[x][y]]) return false;

        visited[sudoku[x][y]] = true;
    }

    return true;
}

bool check_square(int x, int y) {
    memset(visited, 0, sizeof visited);

    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            int nx = x + dx;
            int ny = y + dy;

            if (visited[sudoku[nx][ny]]) return false;

            visited[sudoku[nx][ny]] = true;
        }
    }

    return true;
}

bool check_sudoku() {
    for (int i = 0; i < 9; i++) {
        if (!check_row(i)) return false;
        if (!check_col(i)) return false;
    }

    for (int x = 0; x < 9; x += 3) {
        for (int y = 0; y < 9; y += 3) {
            if (!check_square(x, y)) return false;
        }
    }

    return true;
}

void input() {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            cin >> sudoku[x][y];
        }
    }
}

void pro(int ti) {
    cout << "Case " << ti << ": " << (check_sudoku() ? "CORRECT" : "INCORRECT") << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        input();
        pro(ti);
    }

    return 0;
}
