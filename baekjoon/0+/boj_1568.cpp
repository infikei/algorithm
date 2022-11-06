#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, cnt = 0;
    cin >> N;

    while (N > 0) {
        int n = 1;
        while ((n * (n + 1) / 2) <= N) {
            n++;
        }
        n--;

        N -= (n * (n + 1) / 2);
        cnt += n;
    }

    cout << cnt << '\n';

    return 0;
}