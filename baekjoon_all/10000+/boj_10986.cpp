#include <iostream>
using namespace std;

int arr[1000000], N, M;
long long remainder[1000], ans;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int tmp = 0;
    remainder[0] = 1;
    for (int i = 0; i < N; i++) {
        tmp = (tmp + arr[i]) % M;
        remainder[tmp]++;
    }

    ans = 0;
    for (int i = 0; i < M; i++) {
        if (remainder[i] > 0) {
            ans += remainder[i] * (remainder[i] - 1) / 2;
            // remainder[] 와 ans를 int 자료형으로 설정하면 이 부분에서 잘못된 결과가 나올 수 있으므로 long long 자료형으로 설정해야 한다.
        }
    }

    cout << ans << '\n';

    return 0;
}