#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int M;
        cin >> M;
        cout << M / 2 + 1 << '\n';

        priority_queue<int> pq_max;
        priority_queue<int, vector<int>, greater<int> > pq_min;
        int x;

        for (int m = 1; m <= M; m++) {
            cin >> x;

            if (m % 2 == 1) {
                pq_max.push(x);
                if (!pq_min.empty() && pq_max.top() > pq_min.top()) {
                    pq_min.push(pq_max.top());
                    pq_max.pop();
                    
                    pq_max.push(pq_min.top());
                    pq_min.pop();
                }

                cout << pq_max.top() << ' ';
            }
            else {
                pq_min.push(x);
                if (pq_max.top() > pq_min.top()) {
                    pq_min.push(pq_max.top());
                    pq_max.pop();
                    
                    pq_max.push(pq_min.top());
                    pq_min.pop();
                }
            }

            if (m % 20 == 0) {
                cout << '\n';
            }
        }

        cout << '\n';
    }

    return 0;
}