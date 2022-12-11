#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, M;
    cin >> N >> M;

    bool check_possible = true;
    bool check_possible2 = false;

    if (N % 2 == 1 && M % 2 == 1) {
        check_possible = false;
    }
    else {
        int x, x0, cnt_of_1 = 0;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                cin >> x;
                if (x == 1) {
                    cnt_of_1++;
                }
                if (check_possible2) {
                    continue;
                }
                if (row == 0 && col == 0) {
                    x0 = x;
                }
                else {
                    if (x != (row + col + x0) % 2) {
                        check_possible2 = true;
                    }
                }
            }
        }
        if (cnt_of_1 % 2 == 1) {
            check_possible = false;
        }
    }

    if (check_possible && check_possible2) {
        cout << 1 << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}