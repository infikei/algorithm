// Solve 2023-11-26

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

    int s[200000];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            int max_len = 0;
            int cur_len = 0;

            for (int k = 0; k < n; k++) {
                if (s[k] == i || s[k] == j) {
                    cur_len++;
                }
                else {
                    max_len = max(max_len, cur_len);
                    cur_len = 0;
                }
            }

            max_len = max(max_len, cur_len);
            ans = max(ans, max_len);
        }
    }

    cout << ans << '\n';

    return 0;
}
