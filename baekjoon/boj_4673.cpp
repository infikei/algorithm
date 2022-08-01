#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    bool check[10001] = {false};
    int sum, temp;

    for (int i = 1; i < 10001; i++) {
        sum = i;
        temp = i;

        while (temp > 0) {
            sum += temp % 10;
            temp = temp / 10;
        }

        if (sum < 10001) {
            check[sum] = true;
        }
    }

    for (int i = 1; i < 10001; i++) {
        if (!check[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}