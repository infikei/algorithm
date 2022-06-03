#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool check[10001] = {false};
    int sum;
    string s;

    for (int i = 1; i < 10001; i++)
    {
        sum = i;
        s = to_string(i);

        for (int j = 0; j < s.size(); j++)
        {
            sum += (s[j] - '0');
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