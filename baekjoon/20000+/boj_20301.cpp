#include <iostream>
#include <deque>
using namespace std;

deque<int> q;
int N, K, M;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> K >> M;

    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    int k = 1, m = 1;
    bool q_direction = true;

    while (!q.empty()) {
        if (q_direction) {
            if (k < K) {
                q.push_back(q.front());
                q.pop_front();
                k++;
            }
            else {
                cout << q.front() << '\n';
                q.pop_front();
                k = 1;

                if (m < M) {
                    m++;
                }
                else {
                    q_direction = false;
                    m = 1;
                }
            }
        }
        else {
            if (k < K) {
                q.push_front(q.back());
                q.pop_back();
                k++;
            }
            else {
                cout << q.back() << '\n';
                q.pop_back();
                k = 1;

                if (m < M) {
                    m++;
                }
                else {
                    q_direction = true;
                    m = 1;
                }
            }
        }
    }

    return 0;
}