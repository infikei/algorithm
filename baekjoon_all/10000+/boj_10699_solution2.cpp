// Solve 2023-03-07

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t timer = time(NULL);
    timer += 9 * 60 * 60; // 채점 서버의 시간대는 UTC+0이므로 서울 기준의 시각을 구하려면 9시간을 더해야 한다.
    tm *now = localtime(&timer);

    int yyyy = now->tm_year + 1900;
    int mm = now->tm_mon + 1;
    int dd = now->tm_mday;

    cout << yyyy << '-';

    cout.width(2);
    cout.fill('0');
    cout << mm << '-';

    cout.width(2);
    cout.fill('0');
    cout << dd << '\n';

    return 0;
}