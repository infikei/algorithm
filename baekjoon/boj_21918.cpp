#include <iostream>
using namespace std;

int bulb[4001];
int N, M;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> bulb[i];
    }
}

void print() {
    for (int i = 1; i <= N; i++) {
        cout << bulb[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    for (int m = 0; m < M; m++) {
        int cmd, b, c;
        cin >> cmd;

        if (cmd == 1) {
            cin >> b >> c;
            bulb[b] = c;
        }
        else if (cmd == 2) {
            cin >> b >> c;
            for (int i = b; i <= c; i++) {
                bulb[i] = 1 - bulb[i];
            }
        }
        else if (cmd == 3) {
            cin >> b >> c;
            for (int i = b; i <= c; i++) {
                bulb[i] = 0;
            }
        }
        else {
            cin >> b >> c;
            for (int i = b; i <= c; i++) {
                bulb[i] = 1;
            }
        }
    }

    print();

    return 0;
}