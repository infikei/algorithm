// Solve 2022-12-09
// Update 2025-07-25

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

int len = 1 << 17;
int seg_min[1 << 18];
int seg_max[1 << 18];

void make_seg() {
    for (int i = len - 1; i >= 1; i--) {
        seg_min[i] = min(seg_min[i * 2], seg_min[i * 2 + 1]);
        seg_max[i] = max(seg_max[i * 2], seg_max[i * 2 + 1]);
    }
}

pii get_from_seg(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return {INF, 0};
    if (tl <= l && r <= tr) return {seg_min[idx], seg_max[idx]};

    int mid = (l + r) / 2;
    pii left_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    pii right_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return {min(left_ret.first, right_ret.first), max(left_ret.second, right_ret.second)};
}

int main() {
    FASTIO;

    memset(seg_min, 0x3f, sizeof seg_min);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        seg_min[i + len] = x;
        seg_max[i + len] = x;
    }

    make_seg();

    while (m-- > 0) {
        int a, b;
        cin >> a >> b;
        pii res = get_from_seg(1, 0, len - 1, a, b);
        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}
