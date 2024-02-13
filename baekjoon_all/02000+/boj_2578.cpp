// Solve 2024-02-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int board[5][5];

int count_bingo() {
    bool garo_bingo[5] = { true, true, true, true, true };
    bool sero_bingo[5] = { true, true, true, true, true };
    bool cross_bingo = true;
    bool other_cross_bingo = true;

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (board[x][y] != 0) {
                garo_bingo[x] = false;
                sero_bingo[y] = false;
            }
        }

        if (board[x][x] != 0) {
            cross_bingo = false;
        }

        if (board[x][4 - x] != 0) {
            other_cross_bingo = false;
        }
    }

    int bingo_count = 0;

    for (int i = 0; i < 5; i++) {
        if (garo_bingo[i]) bingo_count++;
        if (sero_bingo[i]) bingo_count++;
    }

    if (cross_bingo) bingo_count++;
    if (other_cross_bingo) bingo_count++;

    return bingo_count;
}

int main() {
    FASTIO;

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cin >> board[x][y];
        }
    }

    int numbers_called[25];

    for (int i = 0; i < 25; i++) {
        cin >> numbers_called[i];
    }

    for (int i = 0; i < 25; i++) {
        int num = numbers_called[i];
        bool flag_found_num = false;

        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (board[x][y] == num) {
                    board[x][y] = 0;
                    flag_found_num = true;
                    break;
                }
            }

            if (flag_found_num) break;
        }

        if (count_bingo() >= 3) {
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}
