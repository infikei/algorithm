// Solve 2024-02-05

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

    int abcd[4000][4];

    for (int i = 0; i < n; i++) {
        cin >> abcd[i][0] >> abcd[i][1] >> abcd[i][2] >> abcd[i][3];
    }

    vector<int> ab(n * n);
    vector<int> cd(n * n);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab[idx] = abcd[i][0] + abcd[j][1];
            cd[idx] = abcd[i][2] + abcd[j][3];
            idx++;
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    ll ans = 0;
    int i = 0;
    int j = n * n - 1;

    while (i < n * n && j >= 0) {
        int cur_val = ab[i] + cd[j];

        if (cur_val < 0) {
            i++;
        }
        else if (cur_val > 0) {
            j--;
        }
        else {
            ll ab_cnt = 1;
            ll cd_cnt = 1;

            while (i + 1 < n * n && ab[i] == ab[i + 1]) {
                i++;
                ab_cnt++;
            }

            while (j >= 1 && cd[j] == cd[j - 1]) {
                j--;
                cd_cnt++;
            }

            i++;
            j--;
            ans += ab_cnt * cd_cnt;
        }
    }

    cout << ans << '\n';

    return 0;
}
