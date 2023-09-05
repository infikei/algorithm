// Solve 2022-12-01
// Update 2023-09-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int cnt[2][26] = { 0 };

        for (int i = 0; i < 2; i++) {
            string s;
            cin >> s;

            for (char c : s) {
                cnt[i][c - 'a']++;
            }
        }

        bool flag = true;

        for (int j = 0; j < 26; j++) {
            if (cnt[0][j] != cnt[1][j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Possible\n";
        }
        else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
