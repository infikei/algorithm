// Solve 2023-02-10

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

string s0, s1;
int dp[1001][1001];

int main() {
    FASTIO;

    cin >> s0 >> s1;
    int len_s0 = SIZE(s0), len_s1 = SIZE(s1);
    for (int i = 1; i <= len_s0; i++) {
        for (int j = 1; j <= len_s1; j++) {
            if (s0[i - 1] == s1[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[len_s0][len_s1] << '\n';

    int cur_row = len_s0, cur_col = len_s1;
    string ans;
    while (cur_row > 0 && cur_col > 0) {
        if (s0[cur_row - 1] == s1[cur_col - 1]) {
            ans = s0[cur_row - 1] + ans;
            cur_row--;
            cur_col--;
        }
        else if (dp[cur_row - 1][cur_col] > dp[cur_row][cur_col - 1]) {
            cur_row--;
        }
        else {
            cur_col--;
        }
    }
    cout << ans << '\n';

    return 0;
}