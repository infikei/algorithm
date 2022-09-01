#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int K;
        cin >> K;

        priority_queue<int> pq_max; // 최댓값이 top에 있는 우선순위 큐
        priority_queue<int, vector<int>, greater<int> > pq_min; // 최솟값이 top에 있는 우선순위 큐
        map<int, int> m; // 저장한 수와 그 중복된 개수를 저장하는 map

        int n;
        char ch;

        for (int k = 0; k < K; k++) {
            cin >> ch >> n;
            
            if (ch == 'I') {
                pq_max.push(n);
                pq_min.push(n);
                m[n]++;
            } else {
                if (!m.empty()) {
                    if (n == 1) {
                        while (!pq_max.empty() && m[pq_max.top()] == 0) {
                            // 맵에 없으면 삭제 (개수가 0이면 top에 있는 값은 유효한 값이 아님)
                            pq_max.pop();
                        }
                        // 최댓값 삭제
                        if (!pq_max.empty()) {
                            m[pq_max.top()]--;
                            pq_max.pop();
                        }
                    } else {
                        while (!pq_min.empty() && m[pq_min.top()] == 0) {
                            // 맵에 없으면 삭제 (개수가 0이면 top에 있는 값은 유효한 값이 아님)
                            pq_min.pop();
                        }
                        // 최솟값 삭제
                        if (!pq_min.empty()) {
                            m[pq_min.top()]--;
                            pq_min.pop();
                        }
                    }
                }
            }
        }

        // 현재 저장되어있는 최댓값과 최솟값이 유효한지 검사해야 한다.

        while (!pq_max.empty() && m[pq_max.top()] == 0) {
            // 맵에 없으면 삭제
            pq_max.pop();
        }

        while (!pq_min.empty() && m[pq_min.top()] == 0) {
            // 맵에 없으면 삭제
            pq_min.pop();
        }

        // 결과 출력
        if (pq_min.empty() || pq_max.empty()) {
            cout << "EMPTY";
        } else {
            cout << pq_max.top() << ' ';
            cout << pq_min.top() << ' ';
        }
        cout << '\n';
    }

    return 0;
}