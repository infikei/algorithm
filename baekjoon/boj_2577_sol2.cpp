#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int a, b, c;
    cin >> a >> b >> c;
    int count[10] = {0};
    string s = to_string(a * b * c);

    for (char ch : s)
    {
        count[ch - '0']++;
    }

    for (int i : count)
    {
        cout << i << "\n";
    }

    return 0;
}