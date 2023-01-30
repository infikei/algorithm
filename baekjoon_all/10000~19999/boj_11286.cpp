#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        else {
            return abs(a) > abs(b);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    priority_queue<int, vector<int>, cmp> pq;
    int N, x, res;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                res = 0;
            }
            else {
                res = pq.top();
                pq.pop();
            }
            cout << res << '\n';
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}