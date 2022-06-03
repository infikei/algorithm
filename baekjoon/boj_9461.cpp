#include <iostream>
using namespace std;

long long DP[101] = {0};

long long P(int N)
{
    if (DP[N] == 0)
        DP[N] = P(N - 1) + P(N - 5);
    return DP[N];
}

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;

    int T, N;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        cout << P(N) << "\n";
    }

    return 0;
}