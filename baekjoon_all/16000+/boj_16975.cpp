// Solve 2023-06-10
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
ll seg[1 << 18];

void add_to_interval(int idx, int l, int r, int tl, int tr, int val) {
    if (r < tl || tr < l) return;
    if (tl <= l && r <= tr) {
        seg[idx] += val;
        return;
    }

    int mid = (l + r) / 2;
    add_to_interval(idx * 2, l, mid, tl, tr, val);
    add_to_interval(idx * 2 + 1, mid + 1, r, tl, tr, val);
}

ll get_from_seg(int idx) {
    idx += len;
    ll ret = seg[idx];
    idx /= 2;

    while (idx >= 1) {
        ret += seg[idx];
        idx /= 2;
    }

    return ret;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> seg[i + len];
    }

    int m;
    cin >> m;

    while (m-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            add_to_interval(1, 0, len - 1, i, j, k);
        }
        else {
            int x;
            cin >> x;
            cout << get_from_seg(x) << '\n';
        }
    }

    return 0;
}
