#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string strArr[100001];
unordered_map<string, int> hs;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    string strTemp;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> strTemp;
        strArr[i] = strTemp;
        hs[strTemp] = i;
    }

    for (int i = 1; i <= M; i++)
    {
        cin >> strTemp;
        if (hs.find(strTemp) != hs.end())
        {
            cout << hs.find(strTemp)->second << "\n";
        }
        else
        {
            cout << strArr[stoi(strTemp)] << "\n";
        }
    }

    return 0;
}