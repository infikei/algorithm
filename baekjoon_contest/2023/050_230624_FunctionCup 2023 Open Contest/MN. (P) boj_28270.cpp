// Solve 2023-06-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int m[1000001], ans[1000001], cnt[1000001];

int main() {
    FASTIO;

    int c;
    cin >> c;

    for (int i = 1; i <= c; i++) {
        cin >> m[i];
    }

    bool is_valid = true;
    for (int i = 1; i <= c; i++) {
        if (m[i] > m[i - 1] + 1) {
            is_valid = false;
            break;
        }
        else if (m[i] < m[i - 1]) {
            ans[i] = ++cnt[m[i]];
            for (int j = m[i] + 1; j < 1000001; j++) {
                if (cnt[j] == 0) break;
                cnt[j] = 0;
            }
        }
        else {
            ans[i] = ++cnt[m[i]];
        }
    }

    if (is_valid) {
        for (int i = 1; i <= c; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
