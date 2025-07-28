// Solve 2022-12-07
// Update 2025-07-27

// 1725번과 동일한 문제
// 분할정복 + 세그먼트 트리를 이용한 풀이

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

int n;
int hist[100000];
int len = 1 << 17;
int seg[1 << 18];

void make_seg() {
    for (int i = 0; i < n; i++) {
        seg[i + len] = i;
    }

    for (int i = len - 1; i >= 1; i--) {
        int l_val = seg[i * 2];
        int r_val = seg[i * 2 + 1];
        seg[i] = (hist[l_val] <= hist[r_val] ? l_val : r_val);
    }
}

int get_from_seg(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return -1;
    if (tl <= l && r <= tr) return seg[idx];

    int mid = (l + r) / 2;
    int l_ret = get_from_seg(idx * 2, l, mid, tl, tr);
    int r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr);

    if (l_ret == -1) return r_ret;
    if (r_ret == -1) return l_ret;
    return hist[l_ret] <= hist[r_ret] ? l_ret : r_ret;
}

ll get_largest_rectangle_area(int l, int r) {
    if (l > r) return 0;

    int lowest_i = get_from_seg(1, 0, len - 1, l, r);
    ll ret = (ll) hist[lowest_i] * (r - l + 1);
    ll l_ret = get_largest_rectangle_area(l, lowest_i - 1);
    ll r_ret = get_largest_rectangle_area(lowest_i + 1, r);
    return max(ret, max(l_ret, r_ret));
}

int main() {
    FASTIO;

    while (true) {
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> hist[i];
        }

        make_seg();
        cout << get_largest_rectangle_area(0, n - 1) << '\n';
    }

    return 0;
}
