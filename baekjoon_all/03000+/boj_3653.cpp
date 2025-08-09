// Solve 2025-08-04

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

int dvd_h[100001];
int len = 1 << 18;
int seg[1 << 19];

void make_seg() {
    for (int i = len - 1; i >= 1; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

void update_seg(int idx, int val) {
    idx += len;

    while (idx >= 1) {
        seg[idx] += val;
        idx /= 2;
    }
}

int get_from_seg(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return 0;
    if (tl <= l && r <= tr) return seg[idx];

    int mid = (l + r) / 2;
    int l_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    int r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return l_ret + r_ret;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        memset(seg, 0, sizeof seg);

        for (int i = 1; i <= n; i++) {
            dvd_h[i] = n + 1 - i;
            seg[i + len] = 1;
        }

        make_seg();
        int last_h = n;

        while (m-- > 0) {
            int x;
            cin >> x;
            int h = dvd_h[x];
            cout << get_from_seg(1, 0, len - 1, h + 1, last_h) << ' ';
            dvd_h[x] = ++last_h;
            update_seg(h, -1);
            update_seg(last_h, 1);
        }

        cout << '\n';
    }

    return 0;
}
