// Solve 2023-02-22

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 1000, MAX_M = 50;
int n, m;
int cnt[MAX_M][4];
char ACGT[4] = { 'A', 'C', 'G', 'T' };

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            char ch = s[j];
            for (int k = 0; k < 4; k++) {
                if (ch == ACGT[k]) {
                    cnt[j][k]++;
                    break;
                }
            }
        }
    }

    string ans;
    int ans2 = n * m;
    for (int j = 0; j < m; j++) {
        int max_val = cnt[j][0], max_idx = 0;
        for (int k = 1; k < 4; k++) {
            if (cnt[j][k] > max_val) {
                max_val = cnt[j][k];
                max_idx = k;
            }
        }
        ans.push_back(ACGT[max_idx]);
        ans2 -= max_val;
    }

    cout << ans << '\n';
    cout << ans2 << '\n';

    return 0;
}