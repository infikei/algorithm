#include <iostream>
using namespace std;

int N, r, c, ans;

int z_func(int N, int r, int c) {
    if (N == 0) {
        return 0;
    }

    int NN = 1 << (N - 1);
    if (r < NN) {
        if (c < NN) {
            return 0 + z_func(N - 1, r, c);
        }
        else {
            return NN * NN + z_func(N - 1, r, c - NN);
        }
    }
    else {
        if (c < NN) {
            return NN * NN * 2 + z_func(N - 1, r - NN, c);
        }
        else {
            return NN * NN * 3 + z_func(N - 1, r - NN, c - NN);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> r >> c;

    ans = z_func(N, r, c);

    cout << ans << '\n';

    return 0;
}