#include <iostream>
using namespace std;

int arr[10];
int ans[10] = {0};
int N;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int arr_i_th_zero = 0;

        for (int j = 0; j < N; j++) {
            if (ans[j] == 0) {
                if (arr_i_th_zero == arr[i]) {
                    ans[j] = i + 1;
                    break;
                }
                else {
                    arr_i_th_zero++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}