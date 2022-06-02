#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int n;
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        for (int i = 1; i <= n - row; i++)
        {
            cout << " ";
        }
        for (int i = 1; i <= row; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}