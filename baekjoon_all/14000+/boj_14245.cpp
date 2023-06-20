// Solve 2023-06-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[500000], seg[2000000], lazy[2000000];

int seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];

    int mid = (s + e) >> 1;
    int left_val = seg_init((node << 1) + 1, s, mid);
    int right_val = seg_init((node << 1) + 2, mid + 1, e);
    return seg[node] = left_val ^ right_val;
}

void seg_lazy_update(int node, int s, int e) {
    if (lazy[node] != 0) {
        if (!((e - s) & 1)) {
            seg[node] ^= lazy[node];
        }

        if (s != e) {
            lazy[(node << 1) + 1] ^= lazy[node];
            lazy[(node << 1) + 2] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void seg_update(int node, int s, int e, int qs, int qe, int qval) {
    if (qe < s || e < qs) {
        seg_lazy_update(node, s, e);
        return;
    }
    if (qs <= s && e <= qe) {
        lazy[node] ^= qval;
        seg_lazy_update(node, s, e);
        return;
    }

    int mid = (s + e) >> 1;
    seg_lazy_update(node, s, e);
    seg_update((node << 1) + 1, s, mid, qs, qe, qval);
    seg_update((node << 1) + 2, mid + 1, e, qs, qe, qval);
    seg[node] = seg[(node << 1) + 1] ^ seg[(node << 1) + 2];
}

int seg_query(int node, int s, int e, int qidx) {
    seg_lazy_update(node, s, e);

    if (qidx < s || e < qidx) return 0;
    if (s == e) return seg[node];

    int mid = (s + e) >> 1;
    int left_val = seg_query((node << 1) + 1, s, mid, qidx);
    int right_val = seg_query((node << 1) + 2, mid + 1, e, qidx);
    return left_val ^ right_val;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    seg_init(0, 0, n - 1);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int qs, qe, qval;
            cin >> qs >> qe >> qval;
            seg_update(0, 0, n - 1, qs, qe, qval);
        }
        else {
            int qidx;
            cin >> qidx;
            cout << seg_query(0, 0, n - 1, qidx) << '\n';
        }
    }

    return 0;
}
