#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int N, k;
int arr[1001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> k;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + (N + 1), greater<int>());

    cout << arr[k] << '\n';

    return 0;
}