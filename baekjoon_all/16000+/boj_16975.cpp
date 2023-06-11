// Solve 2023-06-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll arr[100001], lazy[400001];

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        if (s == e) {
            arr[s] += lazy[node];
        }
        else {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void seg_update(int node, int s, int e, int qs, int qe, ll val) {
    if (qe < s || e < qs) return;
    if (qs <= s && e <= qe) {
        lazy[node] += val;
        return;
    }

    int mid = (s + e) >> 1;
    seg_update(node * 2, s, mid, qs, qe, val);
    seg_update(node * 2 + 1, mid + 1, e, qs, qe, val);
}

ll seg_query(int node, int s, int e, int qidx) {
    seg_lazy_update(node, s, e);

    if (qidx < s || e < qidx) return 0;
    if (s == e) return arr[s];

    int mid = (s + e) >> 1;
    ll left_val = seg_query(node * 2, s, mid, qidx);
    ll right_val = seg_query(node * 2 + 1, mid + 1, e, qidx);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            seg_update(1, 1, n, a, b, c);
        }
        else {
            int x;
            cin >> x;
            cout << seg_query(1, 1, n, x) << '\n';
        }
    }

    return 0;
}
