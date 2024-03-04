// Solve 2024-03-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int board[2000][2000];

int main() {
    FASTIO;

    int n, m;
    char ch;
    cin >> n >> m >> ch;

    if (ch == 'U') {
        int r = n;
        int c = m / 2 + 1;
        int rc = r * c;

        int x = 0;
        int y = c - 1;
        int d = 0;
        int num = 0;

        while (num < rc) {
            board[x][y] = ++num;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] != 0) {
                if (++d == 4) d = 0;

                nx = x + dx[d];
                ny = y + dy[d];
            }

            x = nx;
            y = ny;
        }

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                cout << board[x][y] << ' ';
            }

            for (int y = c - 2; y >= 0; y--) {
                cout << board[x][y] << ' ';
            }

            cout << '\n';
        }
    }
    else if (ch == 'D') {
        int r = n;
        int c = m / 2 + 1;
        int rc = r * c;

        int x = r - 1;
        int y = c - 1;
        int d = 2;
        int num = 0;

        while (num < rc) {
            board[x][y] = ++num;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] != 0) {
                if (--d == -1) d = 3;

                nx = x + dx[d];
                ny = y + dy[d];
            }

            x = nx;
            y = ny;
        }

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                cout << board[x][y] << ' ';
            }

            for (int y = c - 2; y >= 0; y--) {
                cout << board[x][y] << ' ';
            }

            cout << '\n';
        }
    }
    else if (ch == 'L') {
        int r = n / 2 + 1;
        int c = m;
        int rc = r * c;

        int x = r - 1;
        int y = 0;
        int d = 3;
        int num = 0;

        while (num < rc) {
            board[x][y] = ++num;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] != 0) {
                if (--d == -1) d = 3;

                nx = x + dx[d];
                ny = y + dy[d];
            }

            x = nx;
            y = ny;
        }

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                cout << board[x][y] << ' ';
            }

            cout << '\n';
        }

        for (int x = r - 2; x >= 0; x--) {
            for (int y = 0; y < c; y++) {
                cout << board[x][y] << ' ';
            }

            cout << '\n';
        }
    }
    else if (ch == 'R') {
        int r = n / 2 + 1;
        int c = m;
        int rc = r * c;

        int x = r - 1;
        int y = c - 1;
        int d = 1;
        int num = 0;

        while (num < rc) {
            board[x][y] = ++num;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] != 0) {
                if (++d == 4) d = 0;

                nx = x + dx[d];
                ny = y + dy[d];
            }

            x = nx;
            y = ny;
        }

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                cout << board[x][y] << ' ';
            }

            cout << '\n';
        }

        for (int x = r - 2; x >= 0; x--) {
            for (int y = 0; y < c; y++) {
                cout << board[x][y] << ' ';
            }

            cout << '\n';
        }
    }

    return 0;
}
