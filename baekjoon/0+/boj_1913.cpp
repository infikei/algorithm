#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int arr[1001][1001];
    int N, target;
    cin >> N >> target;

    int x = (N + 1) / 2, y = (N + 1) / 2;
    int direction = 0, count = 0, max_count = 1;
    int target_x = x, target_y = y;

    arr[x][y] = 1;
    for (int i = 2; i <= N * N; i++) {
        if (direction == 0) {
            x--;
            arr[x][y] = i;
            count++;
            if (count == max_count) {
                count = 0;
                direction = 1;
            }
        }
        else if (direction == 1) {
            y++;
            arr[x][y] = i;
            count++;
            if (count == max_count) {
                count = 0;
                max_count++;
                direction = 2;
            }
        }
        else if (direction == 2) {
            x++;
            arr[x][y] = i;
            count++;
            if (count == max_count) {
                count = 0;
                direction = 3;
            }
        }
        else if (direction == 3) {
            y--;
            arr[x][y] = i;
            count++;
            if (count == max_count) {
                count = 0;
                max_count++;
                direction = 0;
            }
        }

        if (i == target) {
            target_x = x;
            target_y = y;
        }
    }

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            cout << arr[row][col] << ' ';
        }
        cout << '\n';
    }

    cout << target_x << ' ' << target_y << '\n';

    return 0;
}