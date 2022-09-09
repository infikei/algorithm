#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int a = -1001;

    for (int i = 0; i < N; i++) {
        if (arr[i] == a) {
            continue;
        }
        a = arr[i];
        cout << a << ' ';
    }

    return 0;
}