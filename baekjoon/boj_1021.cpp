#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    cin >> N >> M;

    deque<int> dq;
    int dq_size = N, target, location = 0, ans = 0;

    for (int i = 1; i <= N; i++)
        dq.push_back(i);

    for (int i = 1; i <= M; i++) {
        cin >> target;

        if (dq_size == 1)
            break;

        for (int i = 0; i < dq_size; i++) {
            if (target == dq[i]) {
                location = i;
            }
        }

        int dq_mid = (dq_size + 1) / 2;
        if (location >= dq_mid) {
            for (int j = 1; j <= dq_size - location; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans += dq_size - location;
        }
        else {
            for (int j = 1; j <= location; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            ans += location;
        }
        dq.pop_front();
        dq_size--;
    }

    cout << ans << "\n";

    return 0;
}