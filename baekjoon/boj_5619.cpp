#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N;
int arr[4];
priority_queue<int> pq_max_top;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // input

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq_max_top.push(x);
        if ((int)pq_max_top.size() >= 5) {
            pq_max_top.pop();
        }
    }

    // solve

    int N4 = min(N, 4);

    for (int i = 0; i < N4; i++) {
        arr[i] = pq_max_top.top();
        pq_max_top.pop();
    }

    for (int i = 0; i < N4; i++) {
        string s0 = to_string(arr[i]);

        for (int j = 0; j < N4; j++) {
            if (i == j) {
                continue;
            }

            string s1 = to_string(arr[j]);

            pq_max_top.push(stoi(s0 + s1));
            if ((int)pq_max_top.size() >= 4) {
                pq_max_top.pop();
            }
        }
    }

    // print

    cout << pq_max_top.top() << '\n';

    return 0;
}