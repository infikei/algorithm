#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001];
int N;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    DP[1] = 0;

    for (int i = 2; i <= N; i++) {
        DP[i] = DP[i - 1] + 1;
        if (i % 2 == 0) {
            DP[i] = min((DP[i / 2] + 1), DP[i]);
        }
        if (i % 3 == 0) {
            DP[i] = min((DP[i / 3] + 1), DP[i]);
        }
    }

    cout << DP[N] << '\n';

    return 0;
}