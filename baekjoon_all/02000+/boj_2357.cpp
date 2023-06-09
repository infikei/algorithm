// Solve 2022-12-09
// Update 2023-06-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int arr[100001], seg_min[400001], seg_max[400001];

ostream& operator<<(ostream &os, const pii &rhs) {
    os << rhs.first << ' ' << rhs.second;
    return os;
}

void seg_init(int node, int s, int e) {
    if (s == e) {
        seg_min[node] = seg_max[node] = arr[s];
        return;
    }

    int mid = (s + e) >> 1;
    seg_init(node * 2, s, mid);
    seg_init(node * 2 + 1, mid + 1, e);
    seg_min[node] = min(seg_min[node * 2], seg_min[node * 2 + 1]);
    seg_max[node] = max(seg_max[node * 2], seg_max[node * 2 + 1]);
}

pii seg_query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return { 1e9, 1 };
    if (l <= s && e <= r) {
        return { seg_min[node], seg_max[node] };
    }

    int mid = (s + e) >> 1;
    pii left_val = seg_query(node * 2, s, mid, l, r);
    pii right_val = seg_query(node * 2 + 1, mid + 1, e, l, r);
    return { min(left_val.first, right_val.first), max(left_val.second, right_val.second) };
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        pii ans = seg_query(1, 1, n, a, b);
        cout << ans << '\n';
    }

    return 0;
}
