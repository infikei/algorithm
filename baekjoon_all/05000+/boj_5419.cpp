// Solve 2025-08-05

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

struct Point{
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {
    }

    bool operator<(const Point& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y > rhs.y;
    }
};

Point islands[75000];
int sorted_y[75000];
int len = 1 << 17;
int seg[1 << 18];

void update_seg(int idx) {
    idx += len;

    while (idx >= 1) {
        seg[idx]++;
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
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            islands[i].x = x;
            islands[i].y = y;
            sorted_y[i] = y;
        }

        sort(islands, islands + n);
        sort(sorted_y, sorted_y + n);
        memset(seg, 0, sizeof seg);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int yy = lower_bound(sorted_y, sorted_y + n, islands[i].y) - sorted_y;
            ans += get_from_seg(1, 0, len - 1, yy, n - 1);
            update_seg(yy);
        }

        cout << ans << '\n';
    }

    return 0;
}
