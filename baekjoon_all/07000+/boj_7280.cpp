// Solve 2023-12-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<vector<bool>> check(4, vector<bool>(14, false));

    for (int i = 0; i < 51; i++) {
        char c;
        int x;
        cin >> c >> x;

        if (c == 'S') {
            check[0][x] = true;
        }
        else if (c == 'B') {
            check[1][x] = true;
        }
        else if (c == 'V') {
            check[2][x] = true;
        }
        else {
            check[3][x] = true;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (!check[i][j]) {
                if (i == 0) {
                    cout << "S " << j << '\n';
                }
                else if (i == 1) {
                    cout << "B " << j << '\n';
                }
                else if (i == 2) {
                    cout << "V " << j << '\n';
                }
                else {
                    cout << "K " << j << '\n';
                }
            }
        }
    }

    return 0;
}
