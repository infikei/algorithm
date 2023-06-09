// Solve 2023-06-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Range{
    int l, r;
    Range(int nl = 0, int nr = 0) : l(nl), r(nr) {}
    Range operator+(const Range &rhs) const {
        return { min(l, rhs.l), max(r, rhs.r) };
    }
};

int arr[100000];
Range seg[400000];

Range seg_init(int node, int s, int e) {
    if (s == e) {
        return seg[node] = { arr[s], arr[s] };
    }

    int mid = (s + e) >> 1;
    Range left_val = seg_init(node * 2 + 1, s, mid);
    Range right_val = seg_init(node * 2 + 2, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_update(int node, int s, int e, int idx) {
    if (idx < s || e < idx) return;
    if (s == e) {
        seg[node] = { arr[s], arr[s] };
        return;
    }

    int mid = (s + e) >> 1;
    seg_update(node * 2 + 1, s, mid, idx);
    seg_update(node * 2 + 2, mid + 1, e, idx);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
}

Range seg_query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return { 100000, 0 };
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) >> 1;
    Range left_val = seg_query(node * 2 + 1, s, mid, l, r);
    Range right_val = seg_query(node * 2 + 2, mid + 1, e, l, r);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        seg_init(0, 0, n - 1);

        for (int i = 0; i < k; i++) {
            int q, a, b;
            cin >> q >> a >> b;

            if (q == 0) {
                swap(arr[a], arr[b]);
                seg_update(0, 0, n - 1, a);
                seg_update(0, 0, n - 1, b);
            }
            else {
                Range res = seg_query(0, 0, n - 1, a, b);
                if (res.l == a && res.r == b) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
