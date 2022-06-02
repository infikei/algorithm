#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = (n % 10) * 10 + (n / 10 + n % 10) % 10;
    int count = 1;

    while (n != x)
    {
        x = (x % 10) * 10 + (x / 10 + x % 10) % 10;
        count++;
    }

    cout << count;

    return 0;
}