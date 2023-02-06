#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int arr[21];
    for (int i = 1; i <= 20; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;

        reverse(arr + a, arr + b + 1);
    }

    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}