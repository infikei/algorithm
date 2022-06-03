#include <iostream>
#include <algorithm>
using namespace std;

int DP[300][2];

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int N, score;
    cin >> N;

    for (int row = 0; row < N; row++)
    {
        cin >> score;

        if (row < 2)
        {
            if (row == 0)
            {
                DP[0][0] = score;
                DP[0][1] = 0;
            }
            else
            {
                DP[1][0] = score + DP[0][0];
                DP[1][1] = score;
            }
        }

        DP[row][0] = score + DP[row - 1][1];
        DP[row][1] = score + max(DP[row - 2][0], DP[row - 2][1]);
    }

    cout << max(DP[N - 1][0], DP[N - 1][1]) << "\n";

    return 0;
}