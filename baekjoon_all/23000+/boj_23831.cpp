// Solve 2025-10-26

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, a, b;
int score[100][3];
int memo[100][3][101][101];

int recur(int cur, int cur_place, int cnt1, int cnt2) {
    if (cur == n) {
        return (cnt1 < b ? -INF : 0);
    }

    if (memo[cur][cur_place][cnt1][cnt2] != 0) {
        return memo[cur][cur_place][cnt1][cnt2];
    }

    int mx = -INF;

    for (int i = 0; i < 3; i++) {
        if (cnt2 + (cur_place == 2) > a) continue;
        if (i == 1 && cur_place == 1) continue;

        int res = score[cur][cur_place] + recur(cur + 1, i, min(b, cnt1 + (cur_place == 0)), cnt2 + (cur_place == 2));
        mx = max(mx, res);
    }

    memo[cur][cur_place][cnt1][cnt2] = mx;
    return mx;
}

int main() {
    FASTIO;

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        score[i][0] = max(p, q);
        score[i][1] = r;
        score[i][2] = s;
    }

    int mx = 0;

    for (int i = 0; i < 3; i++) {
        mx = max(mx, recur(0, i, 0, 0));
    }

    cout << mx << '\n';
    return 0;
}
