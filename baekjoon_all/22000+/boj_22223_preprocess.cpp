// Solve 2022-11-22

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int m = 13;
const int n = 3;
const int n2 = n * n;
int arr[n2];

void arr_print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i * n + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool arr_check() {
    unordered_map<int, int> hs;

    int cross_left_sum = 0;
    int cross_right_sum = 0;

    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum *= 10;
            row_sum += arr[i * n + j];
            col_sum *= 10;
            col_sum += arr[j * n + i];
        }
        if (row_sum % m != 0 || hs.find(row_sum) != hs.end()) {
            return false;
        }
        hs[row_sum]++;
        if (col_sum % m != 0 || hs.find(col_sum) != hs.end()) {
            return false;
        }
        hs[col_sum]++;

        cross_left_sum *= 10;
        cross_left_sum += arr[i * (n + 1)];
        cross_right_sum *= 10;
        cross_right_sum += arr[(i + 1) * (n - 1)];
    }

    if (cross_left_sum % m != 0 || hs.find(cross_left_sum) != hs.end()) {
        return false;
    }
    hs[cross_left_sum]++;
    if (cross_right_sum % m != 0 || hs.find(cross_right_sum) != hs.end()) {
        return false;
    }
    hs[cross_right_sum]++;

    return true;
}

void dfs(int depth = 0) {
    if (depth == n2) {
        if (!arr_check()) {
            return;
        }
        arr_print();
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 0 && (depth < n || depth % n == 0)) {
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
    FASTIO;

    dfs();

    return 0;
}