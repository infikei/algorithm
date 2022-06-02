#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int n;
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        cout << i << "\n";
    }

    return 0;
}