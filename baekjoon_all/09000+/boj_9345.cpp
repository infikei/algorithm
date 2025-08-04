// Solve 2023-06-08
// Update 2025-08-03

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

struct Range{
    int l, r;

    Range(int l = 0, int r = 0) : l(l), r(r) {
    }

    Range operator+(const Range& rhs) const {
        return {min(l, rhs.l), max(r, rhs.r)};
    }
};

int len = 1 << 17;
Range seg[1 << 18];

void make_seg() {
    for (int i = len - 1; i >= 1; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

void update_seg(int idx, int val) {
    idx += len;
    seg[idx] = {val, val};
    idx /= 2;

    while (idx >= 1) {
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
        idx /= 2;
    }
}

Range get_from_seg(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return {INF, -INF};
    if (tl <= l && r <= tr) return seg[idx];

    int mid = (l + r) / 2;
    Range l_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    Range r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return l_ret + r_ret;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            seg[i + len] = {i, i};
        }

        make_seg();

        while (k-- > 0) {
            int q, a, b;
            cin >> q >> a >> b;

            if (q == 0) {
                int dvd_at_a = seg[a + len].l;
                int dvd_at_b = seg[b + len].l;
                update_seg(a, dvd_at_b);
                update_seg(b, dvd_at_a);
            }
            else {
                Range ret = get_from_seg(1, 0, len - 1, a, b);
                cout << ((a == ret.l && b == ret.r) ? "YES" : "NO") << '\n';
            }
        }
    }

    return 0;
}
