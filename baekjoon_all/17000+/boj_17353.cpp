// Solve 2023-07-15
// Update 2025-08-10

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

int arr[100001];
int len = 1 << 17;
ll seg[1 << 18];
ll lazy[1 << 18];

void apply_lazy(int idx, int l, int r) {
    seg[idx] += (r - l + 1) * lazy[idx];

    if (l < r) {
        lazy[idx * 2] += lazy[idx];
        lazy[idx * 2 + 1] += lazy[idx];
    }

    lazy[idx] = 0;
}

void update_seg(int idx, int l, int r, int tl, int tr, ll val) {
    if (tr < l || r < tl) {
        apply_lazy(idx, l, r);
        return;
    }
    if (tl <= l && r <= tr) {
        lazy[idx] += val;
        apply_lazy(idx, l, r);
        return;
    }

    apply_lazy(idx, l, r);
    int mid = (l + r) / 2;
    update_seg(idx * 2, l, mid, tl, tr, val);
    update_seg(idx * 2 + 1, mid + 1, r, tl, tr, val);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

void update_seg(int tl, int tr, ll val) {
    update_seg(1, 0, len - 1, tl, tr, val);
}

ll get_from_seg(int idx, int l, int r, int tl, int tr) {
    apply_lazy(idx, l, r);

    if (tr < l || r < tl) return 0;
    if (tl <= l && r <= tr) return seg[idx];

    int mid = (l + r) / 2;
    ll l_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    ll r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return l_ret + r_ret;
}

ll get_from_seg(int tl, int tr) {
    return get_from_seg(1, 0, len - 1, tl, tr);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int l, r;
            cin >> l >> r;
            update_seg(l, r, 1);
            update_seg(r + 1, r + 1, -(r - l + 1));
        }
        else {
            int x;
            cin >> x;
            cout << get_from_seg(1, x) + arr[x] << '\n';
        }
    }

    return 0;
}
