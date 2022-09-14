#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input0, input1;
    cin >> input0 >> input1;

    int input0_sz = input0.length();
    int input1_sz = input1.length();

    if (input0_sz >= input1_sz) {
        cout << "go";
    }
    else {
        cout << "no";
    }
    cout << '\n';

    return 0;
}