#include <iostream>
using namespace std;

int n, m, cnt;
bool check_arr[10];

void dfs(int depth = 0, int k = m) {
    if (k == 0) {
        int j = 1;
        for (int i = 0; i < n - depth; i++) {
            j *= 10;
        }
        cnt += j;
        return;
    }
    else if (depth == n) {
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (check_arr[i]) {
            check_arr[i] = false;
            dfs(depth + 1, k - 1);
            check_arr[i] = true;
        }
        else {
            dfs(depth + 1, k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> n >> m;
    int a;
    for (int i = 0; i < m; i++) {
        cin >> a;
        check_arr[a] = true;
    }

    dfs();
    cout << cnt << '\n';

    return 0;
}