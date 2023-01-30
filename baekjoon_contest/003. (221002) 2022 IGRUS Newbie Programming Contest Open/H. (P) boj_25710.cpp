#include <iostream>
using namespace std;

int N, ans;
int A[1000];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A[x]++;
    }

    for (int i = 1; i < 1000; i++) {
        if (A[i] == 0) {
            continue;
        }
        if (A[i] >= 2) {
            int now = i * i;
            int now2 = 0;
            while (now > 0) {
                now2 += (now % 10);
                now = now / 10;
            }
            ans = max(ans, now2);
        }
        for (int j = i + 1; j < 1000; j++) {
            if (A[j] == 0) {
                continue;
            }
            int now = i * j;
            int now2 = 0;
            while (now > 0) {
                now2 += (now % 10);
                now = now / 10;
            }
            ans = max(ans, now2);
        }
    }

    cout << ans << '\n';

    return 0;
}