// Solve 2023-06-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int table[1000000][5];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> table[i][j];
        }
    }

    int ans = 0, ans1 = 0, ans2 = 1;
    for (int j = 0; j < 5; j++) {
        for (int j2 = j + 1; j2 < 5; j2++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if (table[i][j] == 1 && table[i][j2] == 1) {
                    tmp++;
                }
            }
            if (tmp > ans) {
                ans = tmp;
                ans1 = j;
                ans2 = j2;
            }
        }
    }

    cout << ans << '\n';
    for (int j = 0; j < 5; j++) {
        if (j == ans1 || j == ans2) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }
    cout << '\n';

    return 0;
}
