// Solve 2024-12-28

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

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

    println(ans);

    return 0;
}
