#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    string s;
    int check;

    for (int t = 0; t < T; t++)
    {
        cin >> s;
        check = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                check++;
            }
            else if (s[i] == ')')
            {
                check--;
                if (check < 0)
                {
                    break;
                }
            }
        }

        if (check == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}