#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001];

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int N;
    cin >> N;

    DP[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + 1;
        if (i % 2 == 0)
            DP[i] = min((DP[i / 2] + 1), DP[i]);
        if (i % 3 == 0)
            DP[i] = min((DP[i / 3] + 1), DP[i]);
    }

    cout << DP[N] << "\n";

    return 0;
}