// Solve 2025-10-05

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

int board[4][2];

void do_skill_a() {
    swap(board[0][0], board[2][0]);
    swap(board[0][1], board[2][1]);
    swap(board[1][0], board[3][0]);
    swap(board[1][1], board[3][1]);
}

void do_skill_b() {
    swap(board[0][0], board[1][1]);
    swap(board[0][1], board[1][0]);
    swap(board[2][0], board[3][1]);
    swap(board[2][1], board[3][0]);
}

void do_skill_c() {
    swap(board[0][0], board[3][1]);
    swap(board[1][0], board[2][1]);
    swap(board[2][0], board[1][1]);
    swap(board[3][0], board[0][1]);
}

void do_skill_d() {
    swap(board[0][0], board[1][0]);
    swap(board[1][0], board[2][0]);
    swap(board[2][0], board[3][0]);
    swap(board[3][0], board[3][1]);
    swap(board[3][1], board[2][1]);
    swap(board[2][1], board[1][1]);
    swap(board[1][1], board[0][1]);
}

void do_skill(char c) {
    if (c == 'A') do_skill_a();
    else if (c == 'B') do_skill_b();
    else if (c == 'C') do_skill_c();
    else if (c == 'D') do_skill_d();
}

int main() {
    FASTIO;

    int n, m, k;
    string cmd;
    cin >> n >> m >> k >> cmd;
    board[n - 1][m - 1] = 1;

    for (char& c : cmd) {
        do_skill(c);
    }

    int ham_x = -1;
    int ham_y = -1;

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 2; y++) {
            if (board[x][y] == 1) {
                ham_x = x;
                ham_y = y;
            }
        }
    }

    cout << ham_x + 1 << ' ' << ham_y + 1 << '\n';
    return 0;
}
