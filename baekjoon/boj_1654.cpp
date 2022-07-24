#include <iostream>
using namespace std;

int K_length[10000];
int max_length;
int K, N, ans;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> K >> N;
    max_length = 0;
    for (int i = 0; i < K; i++) {
        cin >> K_length[i];
        if (K_length[i] > max_length) {
            max_length = K_length[i];
        }
    }

    ans = 0;
    long long low = 1, high = max_length, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += K_length[i] / mid;
        }

        if (cnt >= N) {
            low = mid + 1;
            if (mid > ans) {
                ans = mid;
            }
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}