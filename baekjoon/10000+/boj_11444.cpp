#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll N, MOD = 1000000007;
ll mat[2][2] = {{1, 1}, {1, 0}}, tmp[2][2], ans[2][2] = {{1, 0}, {0, 1}};

void calc(ll m1[2][2], ll m2[2][2]) {
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            tmp[row][col] = 0;
            for (int iter = 0; iter < 2; iter++) {
                tmp[row][col] += m1[row][iter] * m2[iter][col] % MOD;
                tmp[row][col] %= MOD;
            }
        }
    }

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            m1[row][col] = tmp[row][col];
        }
    }
}

int main() {
    fastio;

    cin >> N;

    while (N > 0) {
        if (N % 2 == 1) {
            calc(ans, mat);
        }
        calc(mat, mat);
        N /= 2;
    }

    cout << ans[0][1] << '\n';

    return 0;
}