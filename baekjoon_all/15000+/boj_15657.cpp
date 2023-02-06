#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[8], ans[8];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
}

void dfs(int depth = 0, int begin = 0) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = begin; i < N; i++) {
        ans[depth] = arr[i];
        dfs(depth + 1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    dfs();

    return 0;
}