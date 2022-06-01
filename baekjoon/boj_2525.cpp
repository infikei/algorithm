#include <iostream>
using namespace std;

int main()
{
    int hour, minute, extra;

    cin >> hour >> minute >> extra;

    minute += extra;
    while (minute >= 60)
    {
        minute -= 60;
        hour += 1;
    }
    while (hour >= 24)
    {
        hour -= 24;
    }

    cout << hour << ' ' << minute << endl;

    return 0;
}