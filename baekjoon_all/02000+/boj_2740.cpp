// Solve 2022-08-03
// Update 2023-10-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int mat_a[100][100], mat_b[100][100], mat_ans[100][100];

    int n, m, k;
    cin >> n >> m;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> mat_a[row][col];
        }
    }

    cin >> m >> k;

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < k; col++) {
            cin >> mat_b[row][col];
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < k; col++) {
            for (int i = 0; i < m; i++) {
                mat_ans[row][col] += mat_a[row][i] * mat_b[i][col];
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < k; col++) {
            cout << mat_ans[row][col] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
