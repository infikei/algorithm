// Solve 2024-04-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct RotateInfo{
    int r, c, s;
    bool selected = false;
};

int n, m, k;
int board[7][50][50];
RotateInfo rotate_infos[6];
int ans = 5000;

int get_value_of_board(int depth) {
    int min_sum = 5000;

    for (int x = 0; x < n; x++) {
        int cur_sum = 0;

        for (int y = 0; y < m; y++) {
            cur_sum += board[depth][x][y];

            if (cur_sum >= min_sum) break;
        }

        min_sum = cur_sum < min_sum ? cur_sum : min_sum;
    }

    return min_sum;
}

void recur(int depth) {
    if (depth == k) {
        int cur = get_value_of_board(depth);
        ans = cur < ans ? cur : ans;
        return;
    }

    int ndepth = depth + 1;

    for (int i = 0; i < k; i++) {
        if (rotate_infos[i].selected) continue;

        rotate_infos[i].selected = true;
        int r = rotate_infos[i].r;
        int c = rotate_infos[i].c;
        int s = rotate_infos[i].s;

        // 2차원 배열을 복사한다.
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                board[ndepth][x][y] = board[depth][x][y];
            }
        }

        // 복사한 2차원 배열에 회전 연산을 적용한다.
        for (int si = 1; si <= s; si++) {
            int x = r - si;
            int y = c - si;

            while (x < r + si) {
                swap(board[ndepth][x][y], board[ndepth][x + 1][y]);
                x++;
            }

            while (y < c + si) {
                swap(board[ndepth][x][y], board[ndepth][x][y + 1]);
                y++;
            }

            while (x > r - si) {
                swap(board[ndepth][x][y], board[ndepth][x - 1][y]);
                x--;
            }

            while (y > c - si + 1) {
                swap(board[ndepth][x][y], board[ndepth][x][y - 1]);
                y--;
            }
        }

        recur(ndepth);
        rotate_infos[i].selected = false;
    }
}

int main() {
    FASTIO;

    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[0][x][y];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> rotate_infos[i].r >> rotate_infos[i].c >> rotate_infos[i].s;
        rotate_infos[i].r--;
        rotate_infos[i].c--;
    }

    recur(0);
    cout << ans << '\n';

    return 0;
}
