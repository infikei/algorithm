#include <iostream>
using namespace std;

int arr[15];
int N, ans;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    arr[1] = arr[3] = -1;
    arr[2] = arr[5] = 1;
    arr[4] = arr[7] = arr[10] = 2;
    arr[6] = arr[9] = arr[12] = 3;
    arr[8] = arr[11] = arr[14] = 4;
    arr[13] = 5;

    cin >> N;

    if (N >= 15) {
        if (N % 5 < 5) {
            ans = arr[N % 5 + 10] + N / 5 - 2;
        }
        else {
            ans = arr[N % 5] + N / 5;
        }
    }
    else {
        ans = arr[N];
    }

    cout << ans << '\n';

    return 0;
}