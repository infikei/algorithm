// Solve 2022-12-09
// Update 2025-04-08

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

ll arr[1000001];
ll seg[2097152];

ll init_seg(int node, int left, int right) {
    if (left == right) {
        return seg[node] = arr[left];
    }

    int mid = (left + right) / 2;
    ll lval = init_seg(node * 2, left, mid);
    ll rval = init_seg(node * 2 + 1, mid + 1, right);
    return seg[node] = lval + rval;
}

void update_seg(int node, int left, int right, int qidx) {
    if (qidx < left || right < qidx) return;

    if (left == right) {
        seg[node] = arr[qidx];
        return;
    }

    int mid = (left + right) / 2;

    if (qidx <= mid) {
        update_seg(node * 2, left, mid, qidx);
    }
    else {
        update_seg(node * 2 + 1, mid + 1, right, qidx);
    }

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query_seg(int node, int left, int right, int qleft, int qright) {
    if (qright < left || right < qleft) return 0;

    if (qleft <= left && right <= qright) return seg[node];

    int mid = (left + right) / 2;
    ll lval = query_seg(node * 2, left, mid, qleft, qright);
    ll rval = query_seg(node * 2 + 1, mid + 1, right, qleft, qright);
    return lval + rval;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init_seg(1, 1, n);
    m += k;

    while (m-- > 0) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        if (a == 1) {
            arr[b] = c;
            update_seg(1, 1, n, b);
        }
        else {
            cout << query_seg(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}
