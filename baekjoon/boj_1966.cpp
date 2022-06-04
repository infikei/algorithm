#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T, N, M, importance, location;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        queue<int> q;
        queue<int> q_index;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++) {
            cin >> importance;
            q.push(importance);
            q_index.push(i);
            pq.push(importance);
        }

        int ans = 0;

        while (!q.empty()) {
            importance = q.front();
            location = q_index.front();
            q.pop();
            q_index.pop();

            if (importance == pq.top()) {
                pq.pop();
                ans++;
                if (location == M) {
                    cout << ans << "\n";
                    break;
                }
            }
            else {
                q.push(importance);
                q_index.push(location);
            }
        }
    }

    return 0;
}