#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, input, max = 0;
    stack<int> st;
    bool check = true;
    string ans = "";

    cin >> n;

    for (int line = 0; line < n; line++)
    {
        cin >> input;
        while (input > max)
        {
            max++;
            st.push(max);
            ans += "+\n";
        }
        if (input == st.top())
        {
            st.pop();
            ans += "-\n";
        }
        else
        {
            check = false;
            break;
        }
    }

    if (check)
        cout << ans << "\n";
    else
        cout << "NO\n";

    return 0;
}