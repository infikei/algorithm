#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int hour, minute, extra;

    cin >> hour >> minute >> extra;

    minute += extra;
    while (minute >= 60) {
        minute -= 60;
        hour += 1;
    }
    while (hour >= 24) {
        hour -= 24;
    }

    cout << hour << ' ' << minute << '\n';

    return 0;
}