#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int Asize, Bsize, temp, ans;
    cin >> Asize >> Bsize;
    ans = Asize + Bsize;

    unordered_map<int, int> hs;

    for (int i = 0; i < Asize; i++)
    {
        cin >> temp;
        hs[temp]++;
    }
    for (int i = 0; i < Bsize; i++)
    {
        cin >> temp;
        if (hs[temp] == 1)
            ans -= 2;
    }
    cout << ans;

    return 0;
}