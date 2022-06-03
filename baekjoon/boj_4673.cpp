#include <iostream>
using namespace std;

int main()
{
    bool check[10001] = {false};
    int sum, temp;

    for (int i = 1; i < 10001; i++)
    {
        sum = i;
        temp = i;

        while (temp > 0)
        {
            sum += temp % 10;
            temp = temp / 10;
        }

        if (sum < 10001)
        {
            check[sum] = true;
        }
    }

    for (int i = 1; i < 10001; i++)
    {
        if (!check[i])
        {
            cout << i << "\n";
        }
    }

    return 0;
}