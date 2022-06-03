#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    bool check[1001] = {false};

    for (int i = 100; i < 1000; i++)
    {
        if ((i / 10) % 10 * 2 != i / 100 + i % 10)
        {
            check[i] = true;
        }
    }
    check[1000] = true;

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!check[i])
        {
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}