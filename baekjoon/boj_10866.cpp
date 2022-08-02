#include <iostream>
#include <string>
using namespace std;

int d_begin = 0, d_end = 0;
int d[10001];

void push_front(int x) {
    d_begin--;
    if (d_begin < 0)
        d_begin += 10001;
    d[d_begin] = x;
}

void push_back(int x) {
    d[d_end] = x;
    d_end++;
    if (d_end >= 10001)
        d_end -= 10001;
}

int pop_front() {
    if (d_begin == d_end)
        return -1;
    d_begin++;
    if (d_begin >= 10001) {
        d_begin -= 10001;
        return d[10001 - 1];
    }
    return d[d_begin - 1];
}

int pop_back() {
    if (d_begin == d_end)
        return -1;
    d_end--;
    if (d_end < 0)
        d_end += 10001;
    return d[d_end];
}

int size() {
    if (d_begin <= d_end)
        return d_end - d_begin;
    return d_end - d_begin + 10001;
}

int empty() {
    if (d_begin == d_end)
        return 1;
    return 0;
}

int front() {
    if (d_begin == d_end)
        return -1;
    return d[d_begin];
}

int back() {
    if (d_begin == d_end)
        return -1;
    if (d_end == 0)
        return d[10001 - 1];
    return d[d_end - 1];
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

        if (cmd == "push_front") {
            cin >> input;
            push_front(input);
        }
        else if (cmd == "push_back") {
            cin >> input;
            push_back(input);
        }
        else if (cmd == "pop_front") {
            cout << pop_front() << '\n';
        }
        else if (cmd == "pop_back") {
            cout << pop_back() << '\n';
        }
        else if (cmd == "size") {
            cout << size() << '\n';
        }
        else if (cmd == "empty") {
            cout << empty() << '\n';
        }
        else if (cmd == "front") {
            cout << front() << '\n';
        }
        else if (cmd == "back") {
            cout << back() << '\n';
        }
    }

    return 0;
}