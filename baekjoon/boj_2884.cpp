#include <iostream>
using namespace std;

int main()
{
    int hour, minute;

    cin >> hour >> minute;

    if (minute >= 45)
    {
        minute -= 45;
    }
    else
    {
        minute += 15;
        if (hour == 0)
        {
            hour = 23;
        }
        else
        {
            hour -= 1;
        }
    }

    cout << hour << ' ' << minute << endl;

    return 0;
}