#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

const int M = 13;
const int N = 3;
const int N2 = N * N;
int arr[N2];

void arr_print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i * N + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool arr_check() {
    unordered_map<int, int> hs;

    int cross_left_sum = 0;
    int cross_right_sum = 0;

    for (int i = 0; i < N; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < N; j++) {
            row_sum *= 10;
            row_sum += arr[i * N + j];
            col_sum *= 10;
            col_sum += arr[j * N + i];
        }
        if (row_sum % M != 0 || hs.find(row_sum) != hs.end()) {
            return false;
        }
        hs[row_sum]++;
        if (col_sum % M != 0 || hs.find(col_sum) != hs.end()) {
            return false;
        }
        hs[col_sum]++;

        cross_left_sum *= 10;
        cross_left_sum += arr[i * (N + 1)];
        cross_right_sum *= 10;
        cross_right_sum += arr[(i + 1) * (N - 1)];
    }

    if (cross_left_sum % M != 0 || hs.find(cross_left_sum) != hs.end()) {
        return false;
    }
    hs[cross_left_sum]++;
    if (cross_right_sum % M != 0 || hs.find(cross_right_sum) != hs.end()) {
        return false;
    }
    hs[cross_right_sum]++;

    return true;
}

void dfs(int depth = 0) {
    if (depth == N2) {
        if (!arr_check()) {
            return;
        }
        arr_print();
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 0 && (depth < N || depth % N == 0)) {
            continue;
        }
        arr[depth] = i;
        dfs(depth + 1);

        // 시간이 오래 걸리므로 아래 코드를 통해 진행 상황을 확인할 수 있다.
        if (depth == 0) {
            cout << "completed for arr[0] = " << arr[0] << "\n\n";
        }
    }
}

int main() {
    fastio;

    dfs();

    return 0;
}