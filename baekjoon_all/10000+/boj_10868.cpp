// Solve 2022-12-09
// Update 2025-07-26

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
int seg[1 << 18];

void make_seg() {
    for (int i = len - 1; i >= 1; i--) {
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
    }
}

int get_from_seg(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return INF;
    if (tl <= l && r <= tr) return seg[idx];

    int mid = (l + r) / 2;
    int l_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    int r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);
    return min(l_ret, r_ret);
}

int main() {
    FASTIO;

    memset(seg, 0x3f, sizeof seg);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> seg[i + len];
    }

    make_seg();

    while (m-- > 0) {
        int a, b;
        cin >> a >> b;
        cout << get_from_seg(1, 0, len - 1, a, b) << '\n';
    }

    return 0;
}
