#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int N, A[5][5], tmp[5][5], ans[5][5];
ll B;

void calc(int m1[5][5], int m2[5][5]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            tmp[row][col] = 0;
            for (int iter = 0; iter < N; iter++) {
                tmp[row][col] += m1[row][iter] * m2[iter][col];
            }
            tmp[row][col] %= 1000;
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            m1[row][col] = tmp[row][col];
        }
    }
}

void input() {
    cin >> N >> B;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> A[row][col];
        }
        ans[row][row] = 1;
    }
}

void solve() {
    while (B > 0) {
        if (B % 2 == 1) {
            calc(ans, A);
        }
        calc(A, A);
        B /= 2;
    }
}

void print() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << ans[row][col] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastio;

    input();

    solve();

    print();

    return 0;
}