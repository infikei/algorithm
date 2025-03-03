// Solve 2024-12-28
// Update 2025-03-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int gift_cnt[4] = { 0 };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        gift_cnt[x]++;
    }

    int ans = 0;
    int tmp = min(gift_cnt[0], gift_cnt[3]);
    gift_cnt[0] -= tmp;
    gift_cnt[3] -= tmp;
    ans += tmp * 3;

    tmp = min(gift_cnt[1], gift_cnt[2]);
    gift_cnt[1] -= tmp;
    gift_cnt[2] -= tmp;
    ans += tmp * 3;

    tmp = min(gift_cnt[0], gift_cnt[2]);
    gift_cnt[0] -= tmp;
    gift_cnt[2] -= tmp;
    ans += tmp * 2;

    tmp = min(gift_cnt[1], gift_cnt[3]);
    gift_cnt[1] -= tmp;
    gift_cnt[3] -= tmp;
    ans += tmp * 2;

    tmp = min(gift_cnt[0], gift_cnt[1]);
    gift_cnt[0] -= tmp;
    gift_cnt[1] -= tmp;
    ans += tmp;

    tmp = min(gift_cnt[2], gift_cnt[3]);
    gift_cnt[2] -= tmp;
    gift_cnt[3] -= tmp;
    ans += tmp;

    cout << ans << '\n';

    return 0;
}
