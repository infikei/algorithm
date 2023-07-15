// Solve 2023-07-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Pair{
    int a, b;
    Pair(int na = 0, int nb = 0) : a(na), b(nb) {}
    Pair operator+(const Pair &rhs) const {
        Pair res;
        res.a = max(a, rhs.a);
        res.b = max(min(a, rhs.a), max(b, rhs.b));
        return res;
    }
};

int arr[100001];
Pair seg[400001];

Pair seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = { arr[s], 0 };

    int mid = (s + e) >> 1;
    Pair left_val = seg_init(node << 1, s, mid);
    Pair right_val = seg_init((node << 1) + 1, mid + 1, e);
    return seg[node] = left_val + right_val;
}

void seg_update(int node, int s, int e, int qidx, int qval) {
    if (qidx < s || e < qidx) return;
    if (s == e) {
        seg[node] = { qval, 0 };
        return;
    }

    int mid = (s + e) >> 1;
    seg_update(node << 1, s, mid, qidx, qval);
    seg_update((node << 1) + 1, mid + 1, e, qidx, qval);
    seg[node] = seg[node << 1] + seg[(node << 1) + 1];
}

Pair seg_query(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) return { 0, 0 };
    if (qs <= s && e <= qe) return seg[node];

    int mid = (s + e) >> 1;
    Pair left_val = seg_query(node << 1, s, mid, qs, qe);
    Pair right_val = seg_query((node << 1) + 1, mid + 1, e, qs, qe);
    return left_val + right_val;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    seg_init(1, 1, n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            seg_update(1, 1, n, b, c);
        }
        else {
            Pair p = seg_query(1, 1, n, b, c);
            cout << p.a + p.b << '\n';
        }
    }

    return 0;
}
