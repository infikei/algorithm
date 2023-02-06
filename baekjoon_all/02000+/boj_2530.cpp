#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int hour, minute, second, plus;
    cin >> hour >> minute >> second >> plus;

    second += plus;

    minute += second / 60;
    second = second % 60;

    hour += minute / 60;
    minute = minute % 60;

    hour = hour % 24;

    cout << hour << ' ' << minute << ' ' << second << '\n';

    return 0;
}