// Solve 2022-12-06
// Update 2025-04-10

// 6549번과 동일한 문제
// 분할정복 + 세그먼트 트리를 이용한 풀이

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

const int INF = 1000000001;

int histogram[100000];
int seg[262144];

int init_seg(int node, int left, int right) {
    if (left == right) {
        return seg[node] = left;
    }

    int mid = (left + right) / 2;
    int lval = init_seg(node * 2, left, mid);
    int rval = init_seg(node * 2 + 1, mid + 1, right);
    return seg[node] = (histogram[lval] < histogram[rval] ? lval : rval);
}

int query_seg(int node, int left, int right, int qleft, int qright) {
    if (qright < left || right < qleft) return -1;

    if (qleft <= left && right <= qright) return seg[node];

    int mid = (left + right) / 2;
    int lval = query_seg(node * 2, left, mid, qleft, qright);
    int rval = query_seg(node * 2 + 1, mid + 1, right, qleft, qright);

    if (lval == -1) return rval;
    if (rval == -1) return lval;
    return (histogram[lval] < histogram[rval] ? lval : rval);
}

ll get_largest_rectangle(int left, int right, int n) {
    int idx = query_seg(1, 0, n - 1, left, right);
    ll area = (ll) (right - left + 1) * histogram[idx];

    if (left < idx) {
        area = max(area, get_largest_rectangle(left, idx - 1, n));
    }

    if (idx < right) {
        area = max(area, get_largest_rectangle(idx + 1, right, n));
    }

    return area;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> histogram[i];
    }

    init_seg(1, 0, n - 1);
    cout << get_largest_rectangle(0, n - 1, n) << '\n';

    return 0;
}
