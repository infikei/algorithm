#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input0;
    cin >> input0;

    list<char> li(input0.begin(), input0.end());
    list<char>::iterator cur = li.end();

    int M;
    cin >> M;

    for (int m = 0; m < M; m++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cur != li.begin()) {
                cur--;
            }
        }
        else if (cmd == 'D') {
            if (cur != li.end()) {
                cur++;
            }
        }
        else if (cmd == 'B') {
            if (cur != li.begin()) {
                cur--;
                cur = li.erase(cur);
            }
        }
        else {
            char input1;
            cin >> input1;
            li.insert(cur, input1);
        }
    }

    for (list<char>::iterator it = li.begin(); it != li.end(); it++) {
        cout << *it;
    }
    cout << '\n';

    return 0;
}