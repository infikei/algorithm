#include <iostream>
using namespace std;

bool check[1000002];
int cnt;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    long long n_min, n_max;
    cin >> n_min >> n_max;

    cnt = n_max - n_min + 1;

    for (long long i = 2; i * i <= n_max; i++) {
        long long k = n_min / (i * i);

        if (k * i * i < n_min) {
            k++;
        }

        while (k * i * i <= n_max) {
            if (!check[k * (i * i) - n_min]) {
                check[k * (i * i) - n_min] = true;
                cnt--;
            }
            k++;
        }
    }

    cout << cnt << '\n';

    return 0;
}