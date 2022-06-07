#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, k;
    cin >> n >> k;
    if (k > n / 2) {
        k = n - k;
    }

    int ans = 1, j = n;
    for (int i = 1; i <= k; i++) {
        ans *= j;
        ans /= i;
        j--;
    }
    cout << ans;

    return 0;
}