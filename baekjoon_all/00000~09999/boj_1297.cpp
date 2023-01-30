#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int D, H_ratio, W_ratio;
    cin >> D >> H_ratio >> W_ratio;

    int D_ratio = H_ratio * H_ratio + W_ratio * W_ratio;
    int H = D * H_ratio / sqrt(D_ratio);
    int W = D * W_ratio / sqrt(D_ratio);

    cout << H << ' ' << W << '\n';

    return 0;
}