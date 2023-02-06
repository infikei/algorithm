#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        cout << *min_element(arr, arr + N) << ' ';
        cout << *max_element(arr, arr + N) << '\n';
    }

    return 0;
}