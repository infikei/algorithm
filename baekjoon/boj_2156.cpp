#include <iostream>
using namespace std;

int arr[10001];
int DP[10001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    DP[0] = 0;
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 1], max(DP[i - 3] + arr[i - 1] + arr[i], DP[i - 2] + arr[i]));
    }

    cout << DP[n] << '\n';

    return 0;
}