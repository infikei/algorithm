// Solve 2022-12-09
// Update 2025-07-24

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

void make_seg() {
    for (int i = len - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] * tree[i * 2 + 1] % MOD;
    }
}

void update_seg(int idx, ll val) {
    idx += len;
    tree[idx] = val;
    idx /= 2;

    while (idx >= 1) {
        tree[idx] = tree[idx * 2] * tree[idx * 2 + 1] % MOD;
        idx /= 2;
    }
}

ll get_from_seg(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return 1;
    if (tl <= l && r <= tr) return tree[idx];

    int mid = (l + r) / 2;
    ll left_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    ll right_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return left_ret * right_ret % MOD;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;
    m += k;

    for (int i = 1; i <= n; i++) {
        cin >> tree[i + len];
    }

    make_seg();

    while (m-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update_seg(b, c);
        }
        else {
            cout << get_from_seg(1, 0, len - 1, b, c) << '\n';
        }
    }

    return 0;
}
