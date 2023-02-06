#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int sum = 0, arr[9];

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 9);
    sum -= 100;
    int except1 = 0, except2 = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 8; j > i; j--) {
            if (arr[i] + arr[j] == sum) {
                except1 = i;
                except2 = j;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i == except1 || i == except2) {
            continue;
        }
        cout << arr[i] << '\n';
    }

    return 0;
}