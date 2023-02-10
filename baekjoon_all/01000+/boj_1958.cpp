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

string s0, s1, s2;
int dp[101][101][101];

int main() {
    FASTIO;

    cin >> s0 >> s1 >> s2;
    int len_s0 = SIZE(s0), len_s1 = SIZE(s1), len_s2 = SIZE(s2);
    for (int i = 1; i <= len_s0; i++) {
        for (int j = 1; j <= len_s1; j++) {
            for (int k = 1; k <= len_s2; k++) {
                if (s0[i - 1] == s1[j - 1] && s1[j - 1] == s2[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max(max(dp[i][j][k - 1], dp[i][j - 1][k]), dp[i - 1][j][k]);
                }
            }
        }
    }

    cout << dp[len_s0][len_s1][len_s2] << '\n';

    return 0;
}