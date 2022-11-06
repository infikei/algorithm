#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string now_time, complete_time;
    cin >> now_time >> complete_time;

    int h = stoi(complete_time.substr(0, 2)) - stoi(now_time.substr(0, 2));
    int m = stoi(complete_time.substr(3, 2)) - stoi(now_time.substr(3, 2));
    int s = stoi(complete_time.substr(6, 2)) - stoi(now_time.substr(6, 2));

    if (s < 0) {
        s += 60;
        m--;
    }

    if (m < 0) {
        m += 60;
        h--;
    }

    if (h < 0) {
        h += 24;
    }

    cout << h / 10 << h % 10 << ':';
    cout << m / 10 << m % 10 << ':';
    cout << s / 10 << s % 10 << '\n';

    return 0;
}