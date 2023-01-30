#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int arr_max = *max_element(arr, arr + N);
    int arr_min = *min_element(arr, arr + N);

    cout << (arr_max - arr_min) * 2 << '\n';

    return 0;
}