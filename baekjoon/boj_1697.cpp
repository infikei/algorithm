#include <iostream>
#include <queue>
using namespace std;

int N, K;
const int MAX = 100001;
bool visited[MAX];

int bfs() {
    int res = 0;
    queue<int> q;
    q.push(N);
    q.push(-1);

    while (true) {
        int now = q.front();
        q.pop();

        if (now == K) {
            return res;
        }

        if (now == -1) {
            res++;
            q.push(-1);
            continue;
        }

        int next;
        next = now - 1;
        if (next >= 0 && !visited[next]) {
            visited[next] = true;
            q.push(next);
        }
        next = now + 1;
        if (next < MAX && !visited[next]) {
            visited[next] = true;
            q.push(next);
        }
        next = now * 2;
        if (next < MAX && !visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> K;

    cout << bfs() << '\n';

    return 0;
}