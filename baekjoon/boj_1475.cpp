#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string n;
    cin >> n;

    int arr[10] = {0};
    int temp;

    for (int i = 0; i < n.length(); i++) {
        temp = n[i] - '0';
        if (temp == 9) {
            temp = 6;
        }
        arr[temp]++;
    }

    arr[6] = (arr[6] + 1) / 2;

    cout << *max_element(arr, arr + 10) << "\n";

    return 0;
}