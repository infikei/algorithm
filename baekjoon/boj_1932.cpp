#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int n, i, j, temp;
    cin >> n;

    int DP[2][500];
    cin >> DP[0][0];

    for (int row = 1; row < n; row++)
    {
        i = row % 2;
        j = 1 - i;

        cin >> temp;
        DP[i][0] = temp + DP[j][0];

        for (int col = 1; col < row; col++)
        {
            cin >> temp;
            DP[i][col] = temp + max(DP[j][col - 1], DP[j][col]);
        }

        cin >> temp;
        DP[i][row] = temp + DP[j][row - 1];
    }

    cout << *max_element(DP[i], DP[i] + n) << "\n";

    return 0;
}