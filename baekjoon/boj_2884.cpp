#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int hour, minute;

    cin >> hour >> minute;

    if (minute >= 45) {
        minute -= 45;
    }
    else {
        minute += 15;
        if (hour == 0) {
            hour = 23;
        }
        else {
            hour -= 1;
        }
    }

    cout << hour << ' ' << minute << '\n';

    return 0;
}