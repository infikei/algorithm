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

int arr[100001];
pii seg[262144];

ostream& operator<<(ostream &os, const pii &rhs) {
    return os << rhs.first << ' ' << rhs.second;
}

pii init_seg(int node, int left, int right) {
    if (left == right) {
        return seg[node] = { arr[left], arr[left] };
    }

    int mid = (left + right) / 2;
    pii lval = init_seg(node * 2, left, mid);
    pii rval = init_seg(node * 2 + 1, mid + 1, right);
    return seg[node] = { min(lval.first, rval.first), max(lval.second, rval.second) };
}

pii query_seg(int node, int left, int right, int qleft, int qright) {
    if (qright < left || right < qleft) {
        return { 1000000000, 1 };
    }

    if (qleft <= left && right <= qright) {
        return seg[node];
    }

    int mid = (left + right) / 2;
    pii lval = query_seg(node * 2, left, mid, qleft, qright);
    pii rval = query_seg(node * 2 + 1, mid + 1, right, qleft, qright);
    return { min(lval.first, rval.first), max(lval.second, rval.second) };
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init_seg(1, 1, n);

    while (m-- > 0) {
        int a, b;
        cin >> a >> b;

        cout << query_seg(1, 1, n, a, b) << '\n';
    }

    return 0;
}
