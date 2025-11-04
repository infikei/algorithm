// Solve 2025-11-04

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

// 주어진 구간에서 val 이하인 수의 개수를 구한다.
int count_nums_less_or_equal(int idx, int l, int r, int tl, int tr, int val) {
    if (r < tl || tr < l) return 0;
    if (tl <= l && r <= tr) {
        return upper_bound(tree[idx].begin(), tree[idx].end(), val) - tree[idx].begin();
    }

    int mid = (l + r) / 2;
    int l_ret = count_nums_less_or_equal(idx * 2, l, mid, tl, tr, val);
    int r_ret = count_nums_less_or_equal(idx * 2 + 1, mid + 1, r, tl, tr, val);
    return l_ret + r_ret;
}

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        tree[i + len].push_back(v);
    }

    make_seg();

    while (q-- > 0) {
        int s, e, k;
        cin >> s >> e >> k;

        int low = -INF;
        int high = INF;
        int k_th = INF;

        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = count_nums_less_or_equal(1, 0, len - 1, s, e, mid);

            if (cnt >= k) {
                k_th = min(k_th, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << k_th << '\n';
    }

    return 0;
}
