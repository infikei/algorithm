#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int r, c, k;
int A[100][100];
int A_row = 3, A_col = 3;

void sort_r() {
    int max_length = 0;

    for (int row = 0; row < A_row; row++) {
        pii tmp_arr[101];
        for (int i = 0; i < 101; i++) {
            tmp_arr[i] = make_pair(0, i);
        }

        for (int col = 0; col < A_col; col++) {
            (tmp_arr[A[row][col]].first)++;
        }

        sort(tmp_arr, tmp_arr + 101);

        int now_idx = 0;

        for (int i = 0; i < 101; i++) {
            if (tmp_arr[i].first == 0 || tmp_arr[i].second == 0) {
                continue;
            }

            A[row][now_idx] = tmp_arr[i].second;
            now_idx++;
            if (now_idx >= 100) {
                break;
            }

            A[row][now_idx] = tmp_arr[i].first;
            now_idx++;
            if (now_idx >= 100) {
                break;
            }
        }

        for (int i = now_idx; i < 100; i++) {
            A[row][i] = 0;
        }

        max_length = max(max_length, now_idx);
    }

    A_col = max_length;
}

void sort_c() {
    int max_length = 0;

    for (int col = 0; col < A_col; col++) {
        pii tmp_arr[101];
        for (int i = 0; i < 101; i++) {
            tmp_arr[i] = make_pair(0, i);
        }

        for (int row = 0; row < A_row; row++) {
            (tmp_arr[A[row][col]].first)++;
        }

        sort(tmp_arr, tmp_arr + 101);

        int now_idx = 0;

        for (int i = 0; i < 101; i++) {
            if (tmp_arr[i].first == 0 || tmp_arr[i].second == 0) {
                continue;
            }

            A[now_idx][col] = tmp_arr[i].second;
            now_idx++;
            if (now_idx >= 100) {
                break;
            }

            A[now_idx][col] = tmp_arr[i].first;
            now_idx++;
            if (now_idx >= 100) {
                break;
            }
        }

        for (int i = now_idx; i < 100; i++) {
            A[i][col] = 0;
        }

        max_length = max(max_length, now_idx);
    }

    A_row = max_length;
}

int solve() {
    int cnt = 0;

    while (true) {
        if ((r - 1) < A_row && (c - 1) < A_col && A[r - 1][c - 1] == k) {
            return cnt;
        }

        if (cnt >= 100) {
            return -1;
        }

        cnt++;

        if (A_row >= A_col) {
            sort_r();
        }
        else {
            sort_c();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> r >> c >> k;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cin >> A[row][col];
        }
    }

    cout << solve() << '\n';

    return 0;
}