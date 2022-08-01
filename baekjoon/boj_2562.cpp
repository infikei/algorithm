#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int arr[9];
    int max = 0, find = 0;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
            find = i + 1;
        }
    }

    cout << max << '\n';
    cout << find << '\n';

    return 0;
}