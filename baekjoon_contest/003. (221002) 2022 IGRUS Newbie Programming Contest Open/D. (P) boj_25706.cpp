#include <iostream>
using namespace std;

int N;
int H[200001], DP[200001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    for (int i = N; i >= 1; i--) {
        if (i + 1 + H[i] > N) {
            DP[i] = 1;
        }
        else {
            DP[i] = DP[i + 1 + H[i]] + 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << DP[i] << ' ';
    }
    cout << '\n';

    return 0;
}