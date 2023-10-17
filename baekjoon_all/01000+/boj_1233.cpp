// Solve 2023-10-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int cnt[81] = { 0 };

    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                cnt[i + j + k]++;
            }
        }
    }

    int max_val = 0, max_cnt = 0;

    for (int i = 3; i <= 80; i++) {
        if (cnt[i] > max_cnt) {
            max_val = i;
            max_cnt = cnt[i];
        }
    }

    cout << max_val << '\n';

    return 0;
}
