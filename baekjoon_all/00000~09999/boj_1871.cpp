#include <iostream>
#include <string>
using namespace std;

int num26_to_int(string s) {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = s[i] - 'A';
    }

    int res = arr[0] * 26 * 26;
    res += arr[1] * 26;
    res += arr[2];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        string input;
        cin >> input;

        int a = num26_to_int(input.substr(0, 3));
        int b = stoi(input.substr(4, 4));

        if (abs(a - b) <= 100) {
            cout << "nice" << '\n';
        }
        else {
            cout << "not nice" << '\n';
        }
    }

    return 0;
}