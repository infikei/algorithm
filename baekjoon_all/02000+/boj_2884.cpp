// Solve 2021-12-18
// Update 2023-10-09

#include <iostream>
using namespace std;

int main() {
    int hour, minute;
    cin >> hour >> minute;

    minute -= 45;

    if (minute < 0) {
        minute += 60;
        hour--;
    }

    if (hour < 0) {
        hour += 24;
    }

    cout << hour << ' ' << minute << '\n';

    return 0;
}
