#include <iostream>
using namespace std;

int N, K, cnt;

bool check(int a) {
    if (a / 10 == K) {
        return true;
    }
    if (a % 10 == K) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> K;

    cnt = 0;

    for (int h = 0; h <= N; h++) {
        if (check(h)) {
            cnt += 3600;
            continue;
        }
        else {
            for (int m = 0; m < 60; m++) {
                if (check(m)) {
                    cnt += 60;
                    continue;
                }
                else {
                    for (int s = 0; s < 60; s++) {
                        if (check(s)) {
                            cnt += 1;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}