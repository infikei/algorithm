#include <iostream>
#include <algorithm>
using namespace std;

int P[1000];
int N;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    int result = 0;
    for (int i = 0; i < N; i++) {
        result += P[i] * (N - i);
    }

    cout << result << '\n';

    return 0;
}