#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int N;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    int remain = N;

    for (int stage = 1; stage <= N - 1; stage++) {
        int remove = (stage * stage) % remain;
        remove = (remove * stage) % remain;
        if (remove == 0) {
            remove = remain;
        }

        for (int i = 1; i < remove; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
        remain--;
    }

    cout << q.front() << '\n';

    return 0;
}