// Solve 2023-08-22
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point &rhs) const {
        return { x + rhs.x, y + rhs.y };
    }

    Point& operator+=(const Point &rhs) {
        (*this) = (*this) + rhs;
        return *this;
    }
};

const int MAX = 31;
int board[MAX][MAX];
Point direction[4] = {
    { -1, 0 },
    { 0, -1 },
    { 1, 0 },
    { 0, 1 }
};

void make_board() {
    Point cur = { MAX - 1, MAX - 1 };
    int val = MAX * MAX;
    int direction_idx = 0;

    while (--val > 0) {
        board[cur.x][cur.y] = val;
        Point next = cur + direction[direction_idx];

        if (next.x < 0 || next.x >= MAX || next.y < 0 || next.y >= MAX || board[next.x][next.y] != 0) {
            if (++direction_idx == 4) direction_idx = 0;
            next = cur + direction[direction_idx];
        }

        cur = next;
    }
}

void make_entire_cmd(string &cmd) {
    cmd.assign(MAX - 1, 'A');

    for (int i = MAX - 1; i > 0; i -= 2) {
        string x(i, 'X');
        string d(i, 'D');
        string w(i - 1, 'W');
        string a(i - 1, 'A');

        cmd += x + d + w + a;
    }
}

int main() {
    FASTIO;

    make_board();

    string cmd;

    make_entire_cmd(cmd);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;

        int val = board[xi + MAX / 2][yi + MAX / 2];

        cout << cmd.substr(SIZE(cmd) - val, val) << '\n';
    }

    return 0;
}
