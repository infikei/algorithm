#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int temp, ans_sum = 0, ans_min = 1000;

    for (int i = 0; i < 7; i++) {
        cin >> temp;
        if (temp % 2 == 1) {
            ans_sum += temp;
            if (temp < ans_min) {
                ans_min = temp;
            }
        }
    }

    if (ans_min == 1000) {
        cout << -1 << '\n';
    }
    else {
        cout << ans_sum << '\n';
        cout << ans_min << '\n';
    }

    return 0;
}