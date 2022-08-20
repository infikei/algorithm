#include <iostream>
using namespace std;

int N, S[10], B[10], ans = 1000000000;

void dfs(int depth = 0, int S_now = 1, int B_now = 0) {
    if (depth == N) {
        if (B_now == 0) {
            return;
        }
        ans = min(ans, abs(S_now - B_now));
        return;
    }

    dfs(depth + 1, S_now, B_now);
    dfs(depth + 1, S_now * S[depth], B_now + B[depth]);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> B[i];
    }

    dfs();

    cout << ans << '\n';

    return 0;
}