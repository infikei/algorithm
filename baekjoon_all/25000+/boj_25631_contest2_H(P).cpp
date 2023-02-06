#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, cnt;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }

    sort(dq.begin(), dq.end());
    dq.push_back(-1);

    int now = dq.front();
    dq.pop_front();

    while (true) {
        if (dq.front() == -1) {
            cnt++;
            dq.pop_front();
            if (dq.empty()) {
                break;
            }
            now = -1;
            dq.push_back(-1);
        }
        else if (now == dq.front()) {
            dq.push_back(now);
            dq.pop_front();
        }
        else {
            now = dq.front();
            dq.pop_front();
        }
    }

    cout << cnt << '\n';

    return 0;
}