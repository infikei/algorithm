#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> Q;

int solve() {
    for (int i = 2; i <= N; i++) {
        Q.push(i);
    }

    int k = 0;

    while (!Q.empty()) {
        int P = Q.front();
        int Q_size = Q.size();

        for (int i = 0; i < Q_size; i++) {
            int now = Q.front();
            Q.pop();
            if (now % P == 0) {
                k++;
                if (k == K) {
                    return now;
                }
            }
            else {
                Q.push(now);
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> K;

    cout << solve() << '\n';

    return 0;
}