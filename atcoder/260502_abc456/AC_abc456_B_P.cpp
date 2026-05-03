// Solve 2026-05-02

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

int dice_cnt[3][7];

int main() {
    FASTIO;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int d;
            cin >> d;
            dice_cnt[i][d]++;
        }
    }

    int cnt = dice_cnt[0][4] * dice_cnt[1][5] * dice_cnt[2][6];
    cnt += dice_cnt[0][4] * dice_cnt[1][6] * dice_cnt[2][5];
    cnt += dice_cnt[0][5] * dice_cnt[1][4] * dice_cnt[2][6];
    cnt += dice_cnt[0][5] * dice_cnt[1][6] * dice_cnt[2][4];
    cnt += dice_cnt[0][6] * dice_cnt[1][4] * dice_cnt[2][5];
    cnt += dice_cnt[0][6] * dice_cnt[1][5] * dice_cnt[2][4];

    double prob = (double) cnt / 216;
    SETP(10);
    cout << prob << '\n';
    return 0;
}
