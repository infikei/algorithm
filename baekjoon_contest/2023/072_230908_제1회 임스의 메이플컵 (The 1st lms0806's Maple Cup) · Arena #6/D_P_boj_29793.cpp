// Solve 2023-09-08
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, h;
    cin >> n >> h;

    string s;
    cin >> s;

    int ans = 0;

    if (h == 1) {
        ans = 0;
    }
    else if (h == 2) {
        int cnt = 1;

        for (int i = 1, ie = SIZE(s); i <= ie; i++) {
            if (i == ie) {
                ans += cnt / 2;
                break;
            }

            if (s[i - 1] == s[i]) {
                cnt++;
            }
            else {
                ans += cnt / 2;
                cnt = 1;
            }
        }
    }
    else if (h == 3) {
        int cnt[3][3] = { 0 };

        for (int i = 0; i < n; i++) {
            if (s[i] == 'S') cnt[i % 3][0]++;
            else if (s[i] == 'R') cnt[i % 3][1]++;
            else cnt[i % 3][2]++;
        }

        ans = n;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == i) continue;

                for (int k = 0; k < 3; k++) {
                    if (k == i || k == j) continue;

                    ans = min(ans, n - cnt[0][i] - cnt[1][j] - cnt[2][k]);
                }
            }
        }
    }
    else {
        if (n <= 3) {
            int cnt[3] = { 0 };

            for (int i = 0; i < n; i++) {
                if (s[i] == 'S') cnt[0]++;
                else if (s[i] == 'R') cnt[1]++;
                else cnt[2]++;
            }

            for (int i = 0; i < 3; i++) {
                ans += max(0, cnt[i] - 1);
            }
        }
        else {
            ans = -1;
        }
    }

    cout << ans << '\n';

    return 0;
}
