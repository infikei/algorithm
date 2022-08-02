#include <iostream>
#include <string>
using namespace std;

int s_size = 0;
int s[10001];

void push(int x) {
    s[s_size] = x;
    s_size++;
}

int pop() {
    if (s_size == 0)
        return -1;
    s_size--;
    return s[s_size];
}

int size() {
    return s_size;
}

int empty() {
    if (s_size == 0)
        return 1;
    return 0;
}

int top() {
    if (s_size == 0)
        return -1;
    return s[s_size - 1];
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, input;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> input;
            push(input);
        }
        else if (cmd == "pop") {
            cout << pop() << '\n';
        }
        else if (cmd == "size") {
            cout << size() << '\n';
        }
        else if (cmd == "empty") {
            cout << empty() << '\n';
        }
        else if (cmd == "top") {
            cout << top() << '\n';
        }
    }

    return 0;
}