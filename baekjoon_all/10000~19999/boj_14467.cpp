#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, arr[11];
    cin >> N;
    for (int i = 1; i <= 10; i++) {
        arr[i] = -1;
    }

    int cow = 0, location = -1, ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> cow >> location;
        if (arr[cow] != location && arr[cow] != -1) {
            ans++;
        }
        arr[cow] = location;
    }

    cout << ans << '\n';

    return 0;
}