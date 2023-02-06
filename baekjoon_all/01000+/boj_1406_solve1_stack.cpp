#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stck_left;
stack<char> stck_right;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input0;
    cin >> input0;
    int input0_sz = input0.length();

    for (int i = 0; i < input0_sz; i++) {
        stck_left.push(input0[i]);
    }

    int M;
    cin >> M;

    for (int m = 0; m < M; m++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (!stck_left.empty()) {
                stck_right.push(stck_left.top());
                stck_left.pop();
            }
        }
        else if (cmd == 'D') {
            if (!stck_right.empty()) {
                stck_left.push(stck_right.top());
                stck_right.pop();
            }
        }
        else if (cmd == 'B') {
            if (!stck_left.empty()) {
                stck_left.pop();
            }
        }
        else {
            char input1;
            cin >> input1;
            stck_left.push(input1);
        }
    }

    while (!stck_left.empty()) {
        stck_right.push(stck_left.top());
        stck_left.pop();
    }

    while (!stck_right.empty()) {
        cout << stck_right.top();
        stck_right.pop();
    }
    cout << '\n';

    return 0;
}