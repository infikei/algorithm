#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T, N, M, index, importance;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        queue<int> q_index;
        queue<int> q_importance;
        priority_queue<int> pq_importance;

        for (int i = 0; i < N; i++) {
            cin >> importance;
            q_index.push(i);
            q_importance.push(importance);
            pq_importance.push(importance);
        }

        int ans = 0;

        while (!q_importance.empty()) {
            index = q_index.front();
            q_index.pop();
            importance = q_importance.front();
            q_importance.pop();

            if (importance == pq_importance.top()) {
                pq_importance.pop();
                ans++;
                if (index == M) {
                    cout << ans << "\n";
                    break;
                }
            }
            else {
                q_index.push(index);
                q_importance.push(importance);
            }
        }
    }

    return 0;
}