#include <iostream>
using namespace std;

bool visited[9];
int result[9];

void dfs(int n, int m, int depth = 1) {
    if (depth == m + 1) {
        for (int i = 1; i <= m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            result[depth] = i;
            visited[i] = true;
            dfs(n, m, depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, m;
    cin >> n >> m;
    dfs(n, m);

    return 0;
}