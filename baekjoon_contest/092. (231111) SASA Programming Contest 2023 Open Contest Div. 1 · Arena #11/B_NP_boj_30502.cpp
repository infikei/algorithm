// Solve 2023-11-13

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

    vector<vector<int> > table(n + 1, vector<int>(2, -1));

    for (int i = 0; i < m; i++) {
        int a, c;
        char b;
        cin >> a >> b >> c;

        if (b == 'P') {
            table[a][0] = c;
        }
        else {
            table[a][1] = c;
        }
    }

    int ans_min = 0, ans_max = 0;

    for (int i = 1; i <= n; i++) {
        if (table[i][0] == 1 && table[i][1] == 0) ans_min++;
        if (table[i][0] != 0 && table[i][1] != 1) ans_max++;
    }

    cout << ans_min << ' ' << ans_max << '\n';

    return 0;
}
