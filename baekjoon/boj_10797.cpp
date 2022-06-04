#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int n, x, ans = 0;
    cin >> n;

    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        if (n == x)
        {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}