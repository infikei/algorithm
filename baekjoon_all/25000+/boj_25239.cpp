#include <iostream>
#include <string>
using namespace std;

int recover[6], now_hour, now_minute, L, h;
double event_time;
string now_time, event;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> now_time;
    now_hour = stoi(now_time.substr(0, 2));
    now_minute = stoi(now_time.substr(3, 2));

    for (int i = 0; i < 6; i++) {
        cin >> recover[i];
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> event_time >> event;

        if (event == "^") {
            recover[now_hour / 2] = 0;
        }
        else if (event == "10MIN") {
            now_minute += 10;
        }
        else if (event == "30MIN") {
            now_minute += 30;
        }
        else if (event == "50MIN") {
            now_minute += 50;
        }
        else if (event == "2HOUR") {
            now_hour += 2;
        }
        else if (event == "4HOUR") {
            now_hour += 4;
        }
        else if (event == "9HOUR") {
            now_hour += 9;
        }

        if (now_minute >= 60) {
            now_minute -= 60;
            now_hour += 1;
        }
        if (now_hour >= 12) {
            now_hour -= 12;
        }
    }

    h = 0;
    for (int i = 0; i < 6; i++) {
        h += recover[i];
    }
    if (h > 100) {
        h = 100;
    }
    cout << h << '\n';

    return 0;
}