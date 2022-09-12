#include <iostream>
#include <algorithm>
using namespace std;

int arr[81];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    for (int i = 0; i < 81; i++) {
        cin >> arr[i];
    }

    int idx = max_element(arr, arr + 81) - arr;
    cout << arr[idx] << '\n';
    cout << idx / 9 + 1 << ' ';
    cout << idx % 9 + 1 << '\n';

    return 0;
}