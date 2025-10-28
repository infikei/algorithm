// Solve 2025-10-27

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
vector<int> tree[1 << 18];

void make_seg() {
    for (int u = len - 1; u >= 1; u--) {
        vector<int>& left = tree[u * 2];
        vector<int>& right = tree[u * 2 + 1];
        int i = 0;
        int j = 0;

        while (i < size(left) && j < size(right)) {
            if (left[i] < right[j]) {
                tree[u].push_back(left[i]);
                i++;
            }
            else {
                tree[u].push_back(right[j]);
                j++;
            }
        }

        while (i < size(left)) {
            tree[u].push_back(left[i]);
            i++;
        }

        while (j < size(right)) {
            tree[u].push_back(right[j]);
            j++;
        }
    }
}

int get_from_seg(int idx, int l, int r, int tl, int tr, int val) {
    if (r < tl || tr < l) return 0;
    if (tl <= l && r <= tr) {
        return tree[idx].end() - upper_bound(tree[idx].begin(), tree[idx].end(), val);
    }

    int mid = (l + r) / 2;
    int l_ret = get_from_seg(idx * 2, l, mid, tl, tr, val);
    int r_ret = get_from_seg(idx * 2 + 1, mid + 1, r, tl, tr, val);
    return l_ret + r_ret;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        tree[i + len].push_back(v);
    }

    make_seg();

    int q;
    cin >> q;

    while (q-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << get_from_seg(1, 0, len - 1, a, b, c) << '\n';
    }

    return 0;
}
