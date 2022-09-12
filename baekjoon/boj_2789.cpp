#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string target = "CAMBRIDGE";
    string input0;
    cin >> input0;
    int target_sz = target.length();
    int input0_sz = input0.length();

    for (int i = 0; i < input0_sz; i++) {
        bool check = true;
        for (int j = 0; j < target_sz; j++) {
            if (input0[i] == target[j]) {
                check = false;
                break;
            }
        }

        if (check) {
            cout << input0[i];
        }
    }
    cout << '\n';

    return 0;
}