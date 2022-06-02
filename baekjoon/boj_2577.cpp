#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int a, b, c;
    cin >> a >> b >> c;
    int count[10] = {0};
    int abc = a * b * c;

    while (abc > 0)
    {
        count[abc % 10]++;
        abc /= 10;
    }

    for (int i : count)
    {
        cout << i << "\n";
    }

    return 0;
}