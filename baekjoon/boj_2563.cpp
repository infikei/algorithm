#include <iostream>
using namespace std;

bool graph[101][101];
int N, ans = 0;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    for (int n = 0; n < N; n++) {
        int x, y;
        cin >> x >> y;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                graph[x + i][y + j] = true;
            }
        }
    }

    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (graph[i][j]) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}