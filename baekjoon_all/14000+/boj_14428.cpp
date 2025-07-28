// Solve 2023-06-12
// Update 2025-07-27

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
pii seg[1 << 18];

void make_seg() {
    for (int i = len - 1; i >= 1; i--) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}

void update_seg(int idx, int val) {
    idx += len;
    seg[idx].first = val;
    idx /= 2;

    while (idx >= 1) {
        seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
        idx /= 2;
    }
}

pii get_from_seg(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return {INF, 0};
    if (tl <= l && r <= tr) return seg[idx];

    int mid = (l + r) / 2;
    pii l_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    pii r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return min(l_ret, r_ret);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        seg[i + len] = {v, i};
    }

    make_seg();
    int m;
    cin >> m;

    while (m-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int i, v;
            cin >> i >> v;
            update_seg(i, v);
        }
        else {
            int i, j;
            cin >> i >> j;
            pii res = get_from_seg(1, 0, len - 1, i, j);
            cout << res.second << '\n';
        }
    }

    return 0;
}
