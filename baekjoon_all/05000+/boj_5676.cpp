// Solve 2025-07-25

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
int tree[1 << 18];

void make_seg_tree() {
    for (int i = len - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] * tree[i * 2 + 1];
    }
}

void update_seg_tree(int idx, int val) {
    idx += len;
    tree[idx] = val;
    idx /= 2;

    while (idx >= 1) {
        tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
        idx /= 2;
    }
}

int get_from_seg_tree(int idx, int l, int r, int tl, int tr) {
    if (r < tl || tr < l) return 1;
    if (tl <= l && r <= tr) return tree[idx];

    int mid = (l + r) / 2;
    int left_ret = get_from_seg_tree(idx * 2, l, mid, tl, tr);
    int right_ret = get_from_seg_tree(idx * 2 + 1, mid + 1, r, tl, tr);
    return left_ret * right_ret;
}

int main() {
    FASTIO;

    int n, k;

    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tree[i + len] = x > 0 ? 1 : x < 0 ? -1 : 0;
        }

        make_seg_tree();

        while (k-- > 0) {
            char cmd;
            cin >> cmd;

            if (cmd == 'C') {
                int i, v;
                cin >> i >> v;
                update_seg_tree(i, v > 0 ? 1 : v < 0 ? -1 : 0);
            }
            else {
                int i, j;
                cin >> i >> j;
                int res = get_from_seg_tree(1, 0, len - 1, i, j);
                cout << (res > 0 ? '+' : res < 0 ? '-' : '0');
            }
        }

        cout << '\n';
    }

    return 0;
}
