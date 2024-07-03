// Solve 2023-08-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int> > mat(n, vector<int>(n));

    for (auto &vec : mat) {
        for (int &x : vec) {
            cin >> x;
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int row;
            cin >> row;

            row--;

            for (int col = n - 2; col >= 0; col--) {
                swap(mat[row][col], mat[row][col + 1]);
            }
        }
        else {
            vector<vector<int> > new_mat(n, vector<int>(n));

            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    new_mat[col][n - 1 - row] = mat[row][col];
                }
            }

            swap(mat, new_mat);
        }
    }

    for (const auto &vec : mat) {
        for (const int &x : vec) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
