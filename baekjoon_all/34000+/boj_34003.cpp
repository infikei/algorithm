// Solve 2025-05-27

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

string board[8];
int dx[4] = { -1, -1, 0, 0 };
int dy[4] = { -1, 0, -1, 0 };

int get_comb(int n, int r) {
    int res = 1;

    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }

    return res;
}

double get_prob(int o_cnt, int adj_cnt) {
    int child = get_comb(o_cnt - adj_cnt, 4);
    int parent = get_comb(o_cnt, 4);
    return (double) (parent - child) / parent;
}

int main() {
    FASTIO;

    for (int x = 0; x < 8; x++) {
        cin >> board[x];
    }

    int o_cnt = 0;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (board[x][y] == 'O') o_cnt++;
        }
    }

    double probs[5];

    for (int i = 0; i < 5; i++) {
        probs[i] = get_prob(o_cnt, i);
    }

    int max_x = 1;
    int max_y = 1;
    int max_adj_cnt = 0;

    for (int x = 1; x < 8; x++) {
        for (int y = 1; y < 8; y++) {
            int adj_cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (board[nx][ny] == 'O') adj_cnt++;
            }

            if (adj_cnt > max_adj_cnt) {
                max_adj_cnt = adj_cnt;
                max_x = x;
                max_y = y;
            }
        }
    }

    cout << max_x << ' ' << max_y << '\n';
    SETP(9);
    cout << probs[max_adj_cnt] << '\n';
    return 0;
}
