#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    priority_queue<int> pq_less;
    priority_queue<int, vector<int>, greater<int> > pq_greater;
    int N, input;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;

        pq_less.push(input);
        if (pq_less.size() - pq_greater.size() >= 2) {
            pq_greater.push(pq_less.top());
            pq_less.pop();
        }
        if (!pq_greater.empty() && pq_less.top() > pq_greater.top()) {
            int pq_less_val = pq_less.top();
            int pq_greater_val = pq_greater.top();
            pq_less.pop();
            pq_greater.pop();
            pq_less.push(pq_greater_val);
            pq_greater.push(pq_less_val);
        }

        cout << pq_less.top() << '\n';
    }

    return 0;
}