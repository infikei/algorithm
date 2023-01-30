#include <iostream>
using namespace std;

int R, C, W, ans;
int PASCAL[30][30];

int calc_pascal(int r, int c) {
    if (PASCAL[r][c] > 0) {
        return PASCAL[r][c];
    }
    if (c == 1) {
        PASCAL[r][1] = 1;
        return 1;
    }
    if (c == r) {
        PASCAL[r][r] = 1;
        return 1;
    }
    
    PASCAL[r][c] = calc_pascal(r - 1, c - 1) + calc_pascal(r - 1, c);
    return PASCAL[r][c];
}

void solve() {
    for (int row = R; row < R + W; row++) {
        for (int col = C; col < C + row - R + 1; col++) {
            ans += calc_pascal(row, col);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> R >> C >> W;

    solve();

    cout << ans << '\n';

    return 0;
}