// Solve 2023-06-12
// Update 2025-10-27

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

int len = 1 << 20;
ll tree[1 << 21];
ll lazy[1 << 21];

void make_seg() {
    for (int i = len - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

void lazy_update_seg(int idx, int l, int r) {
    tree[idx] += (r - l + 1) * lazy[idx];

    if (idx < len) {
        lazy[idx * 2] += lazy[idx];
        lazy[idx * 2 + 1] += lazy[idx];
    }

    lazy[idx] = 0;
}

void update_seg(int idx, int l, int r, int tl, int tr, ll val) {
    lazy_update_seg(idx, l, r);

    if (r < tl || tr < l) return;
    if (tl <= l && r <= tr) {
        lazy[idx] += val;
        lazy_update_seg(idx, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update_seg(idx * 2, l, mid, tl, tr, val);
    update_seg(idx * 2 + 1, mid + 1, r, tl, tr, val);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll get_from_seg(int idx, int l, int r, int tl, int tr) {
    lazy_update_seg(idx, l, r);

    if (r < tl || tr < l) return 0;
    if (tl <= l && r <= tr) return tree[idx];

    int mid = (l + r) / 2;
    ll l_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    ll r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return l_ret + r_ret;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> tree[i + len];
    }

    make_seg();
    int q = m + k;

    while (q-- > 0) {
        int cmd, b, c;
        cin >> cmd >> b >> c;

        if (cmd == 1) {
            ll d;
            cin >> d;
            update_seg(1, 0, len - 1, b, c, d);
        }
        else {
            cout << get_from_seg(1, 0, len - 1, b, c) << '\n';
        }
    }

    return 0;
}
