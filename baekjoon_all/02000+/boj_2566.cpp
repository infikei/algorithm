// Solve 2022-09-13
// Update 2024-01-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int max_num = -1;
    int row_of_max_num = -1;
    int col_of_max_num = -1;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int num;
            cin >> num;

            if (num > max_num) {
                max_num = num;
                row_of_max_num = i;
                col_of_max_num = j;
            }
        }
    }

    cout << max_num << '\n';
    cout << row_of_max_num << ' ' << col_of_max_num << '\n';

    return 0;
}
