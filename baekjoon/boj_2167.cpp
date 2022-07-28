#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, m;
    cin >> n >> m;

    int arr[301][301];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int arr2[301][301] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr2[i][j] = arr[i][j] + arr2[i][j - 1] + arr2[i - 1][j] - arr2[i - 1][j - 1];
        }
    }

    int k;
    cin >> k;

    for (int t = 0; t < k; t++) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        cout << arr2[x][y] - arr2[x][j - 1] - arr2[i - 1][y] + arr2[i - 1][j - 1] << '\n';
    }

    return 0;
}