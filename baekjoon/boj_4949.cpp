#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    int li[101];
    int li_size;
    bool check;

    while (true)
    {
        getline(cin, input); // getline : 한 줄씩 입력받는 함수 (기존 cin 함수는 공백 기준으로 나누어서 입력을 받음)
        li_size = 0;
        check = true;

        if (input == ".")
            break;

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '(')
            {
                li[li_size] = 1;
                li_size++;
            }
            else if (input[i] == '[')
            {
                li[li_size] = 2;
                li_size++;
            }
            else if (input[i] == ')')
            {
                li_size--;
                if (li_size < 0)
                {
                    check = false;
                    break;
                }
                if (li[li_size] != 1)
                {
                    check = false;
                    break;
                }
            }
            else if (input[i] == ']')
            {
                li_size--;
                if (li_size < 0)
                {
                    check = false;
                    break;
                }
                if (li[li_size] != 2)
                {
                    check = false;
                    break;
                }
            }
        }

        if (li_size != 0)
            check = false;
        if (check)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}