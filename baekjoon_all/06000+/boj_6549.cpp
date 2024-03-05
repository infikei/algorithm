// Solve 2022-12-07
// Update 2024-03-04

// 1725번과 동일한 문제
// 분할정복 + 세그먼트 트리를 이용한 풀이

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n;
int histogram[100000];
int seg[400000];
ll ans;

int seg_init(int node, int s, int e) {
    if (s == e) return seg[node] = s;

    int mid = (s + e) / 2;
    int left_init = seg_init(node * 2, s, mid);
    int right_init = seg_init(node * 2 + 1, mid + 1, e);

    return seg[node] = histogram[left_init] < histogram[right_init] ? left_init : right_init;
}

int seg_query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return -1;
    if (l <= s && e <= r) return seg[node];

    int mid = (s + e) / 2;
    int left_query = seg_query(node * 2, s, mid, l, r);
    int right_query = seg_query(node * 2 + 1, mid + 1, e, l, r);

    if (left_query == -1) return right_query;
    if (right_query == -1) return left_query;
    return histogram[left_query] < histogram[right_query] ? left_query : right_query;
}

ll get_largest_area(int l, int r) {
    int min_idx = seg_query(1, 0, n - 1, l, r);
    ll res = (ll)(r - l + 1) * histogram[min_idx];

    if (l <= min_idx - 1) {
        res = max(res, get_largest_area(l, min_idx - 1));
    }

    if (min_idx + 1 <= r) {
        res = max(res, get_largest_area(min_idx + 1, r));
    }

    return res;
}

int main() {
    FASTIO;

    while (true) {
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> histogram[i];
        }

        seg_init(1, 0, n - 1);
        ans = get_largest_area(0, n - 1);
        cout << ans << '\n';
    }

    return 0;
}
