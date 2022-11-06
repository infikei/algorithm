#include <iostream>
#include <queue>
using namespace std;

int A, B, ans;
queue<int> q;

int bfs(int depth = 1) {
    if (depth >= 31) {
        return -1;
    }

    if (depth == 1) {
        q.push(A);
        return bfs(2);
    }

    int k = q.size();
    for (int i = 0; i < k; i++) {
        int now = q.front();
        q.pop();
        if (now * 2 < B) {
            q.push(now * 2);
        }
        else if (now * 2 == B) {
            return depth;
        }
        if (now <= 100000000 && now * 10 + 1 < B) {
            q.push(now * 10 + 1);
        }
        else if (now <= 100000000 && now * 10 + 1 == B) {
            return depth;
        }
    }

    return bfs(depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> A >> B;

    ans = bfs();

    cout << ans << '\n';

    return 0;
}