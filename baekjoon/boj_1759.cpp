#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[15], ans[15];

void dfs(int depth, int start = 0, int ae = 1, int not_ae = 2) {
    if (depth == 0) {
        if (ae <= 0 && not_ae <= 0) {
            for (int i = 0; i < L; i++) {
                cout << ans[i];
            }
            cout << "\n";
        }
    }
    else {
        for (int i = start; i < C; i++) {
            ans[L - depth] = arr[i];
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                dfs(depth - 1, i + 1, ae - 1, not_ae);
            }
            else {
                dfs(depth - 1, i + 1, ae, not_ae - 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + C);

    dfs(L);

    return 0;
}