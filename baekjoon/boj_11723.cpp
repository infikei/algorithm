#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int M;
    cin >> M;

    int check = 0;

    for (int m = 0; m < M; m++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;
            check = check | (1 << (x - 1));
        }
        else if (cmd == "remove") {
            int x;
            cin >> x;
            check = check & ~(1 << (x - 1));
        }
        else if (cmd == "check") {
            int x;
            cin >> x;
            if ((check & (1 << (x - 1))) == 0) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else if (cmd == "toggle") {
            int x;
            cin >> x;
            check = check ^ (1 << (x - 1));
        }
        else if (cmd == "all") {
            check = 1048575;
        }
        else {
            check = 0;
        }
    }

    return 0;
}