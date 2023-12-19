// Solve 2023-03-07
// Update 2023-12-19

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    time_t timer = time(NULL);
    timer += 9 * 60 * 60; // 채점 서버의 시간대는 UTC+0이므로 UTC+9인 서울 기준의 시각을 구하려면 9시간을 더해야 한다.
    tm *now = localtime(&timer);

    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;

    cout << year << '-';
    cout << setfill('0') << setw(2) << month << '-';
    cout << setfill('0') << setw(2) << day << '\n';

    return 0;
}
