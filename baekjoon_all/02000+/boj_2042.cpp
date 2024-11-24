// Solve 2022-12-09
// Update 2024-11-24

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

ll arr[1000001];
ll seg[4000001];

ll init_seg(int node, int left, int right) {
    if (left == right) {
        return seg[node] = arr[left];
    }

    int mid = (left + right) >> 1;
    ll lval = init_seg(node * 2, left, mid);
    ll rval = init_seg(node * 2 + 1, mid + 1, right);
    return seg[node] = lval + rval;
}

void update_seg(int node, int left, int right, int qidx) {
    if (qidx < left || right < qidx) {
        return;
    }

    if (left == right) {
        seg[node] = arr[qidx];
        return;
    }

    int mid = (left + right) >> 1;
    update_seg(node * 2, left, mid, qidx);
    update_seg(node * 2 + 1, mid + 1, right, qidx);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query_seg(int node, int left, int right, int qleft, int qright) {
    if (qright < left || right < qleft) {
        return 0;
    }

    if (qleft <= left && right <= qright) {
        return seg[node];
    }

    int mid = (left + right) >> 1;
    ll lval = query_seg(node * 2, left, mid, qleft, qright);
    ll rval = query_seg(node * 2 + 1, mid + 1, right, qleft, qright);
    return lval + rval;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int u = 1; u <= n; u++) {
        cin >> arr[u];
    }

    init_seg(1, 1, n);
    m += k;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        if (a == 1) {
            arr[b] = c;
            update_seg(1, 1, n, b);
        }
        else {
            println(query_seg(1, 1, n, b, c));
        }
    }

    return 0;
}
