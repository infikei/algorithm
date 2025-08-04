// Solve 2023-06-23
// Update 2025-08-03

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

int len = 1 << 21;
int seg[1 << 22];

void update_seg(int idx, int val) {
    idx += len;
    seg[idx] += val;
    idx /= 2;

    while (idx >= 1) {
        seg[idx] += val;
        idx /= 2;
    }
}

int get_from_seg(int idx, int l, int r, int val) {
    seg[idx]--;

    if (l == r) return l;

    int mid = (l + r) / 2;

    if (seg[idx * 2] >= val) {
        return get_from_seg(idx * 2, l, mid, val);
    }
    else {
        return get_from_seg(idx * 2 + 1, mid + 1, r, val - seg[idx * 2]);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            update_seg(x, 1);
        }
        else {
            cout << get_from_seg(1, 0, len - 1, x) << '\n';
        }
    }

    return 0;
}
