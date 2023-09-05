// Solve 2022-10-14
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

    int n, m;
    cin >> n >> m;

    string s[10], s2[10];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> s2[i];
    }

    bool flag = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != s2[i][j * 2] || s[i][j] != s2[i][j * 2 + 1]) {
                flag = false;
                break;
            }
        }

        if (!flag) break;
    }

    if (flag) {
        cout << "Eyfa\n";
    }
    else {
        cout << "Not Eyfa\n";
    }

    return 0;
}
