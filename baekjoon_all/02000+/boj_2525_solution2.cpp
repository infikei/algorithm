// Solve 2022-06-02
// Update 2023-10-09

#include <iostream>
using namespace std;

int main() {
    int hour, minute, extra;
    cin >> hour >> minute >> extra;

    minute += extra;

    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }

    if (hour >= 24) {
        hour %= 24;
    }

    cout << hour << ' ' << minute << '\n';

    return 0;
}
