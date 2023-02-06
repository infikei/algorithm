#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int table[2][2], max_cnt;
double max_val;

void rotate_table() {
    int tmp = table[0][0];
    table[0][0] = table[1][0];
    table[1][0] = table[1][1];
    table[1][1] = table[0][1];
    table[0][1] = tmp;
}

double calc_table() {
    return (double)table[0][0] / table[1][0] + (double)table[0][1] / table[1][1];
}

int main() {
    fastio;

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            cin >> table[row][col];
        }
    }

    for (int i = 0; i < 4; i++) {
        double d = calc_table();
        if (d > max_val) {
            max_cnt = i;
            max_val = d;
        }
        rotate_table();
    }

    cout << max_cnt << '\n';

    return 0;
}