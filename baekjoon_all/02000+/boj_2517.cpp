// Solve 2025-08-03

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

int arr[500000];
int sorted_arr[500000];
int len = 1 << 19;
int seg[1 << 20];

void update_seg(int idx) {
    idx += len;
    seg[idx]++;
    idx /= 2;

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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }

    sort(sorted_arr, sorted_arr + n);

    for (int i = 0; i < n; i++) {
        int sorted_idx = lower_bound(sorted_arr, sorted_arr + n, arr[i]) - sorted_arr;
        cout << get_from_seg(1, 0, len - 1, sorted_idx + 1, n - 1) + 1 << '\n';
        update_seg(sorted_idx);
    }

    return 0;
}
