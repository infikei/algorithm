// 1725번과 동일한 문제
// 분할정복 + 세그먼트 트리를 이용한 풀이법

#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int N, histogram[100000], seg[400000];
ll ans;

int seg_init(int node, int s, int e) {
    if (s == e) {
        return seg[node] = s;
    }

    int mid = (s + e) / 2;
    int left_init = seg_init(node * 2, s, mid);
    int right_init = seg_init(node * 2 + 1, mid + 1, e);

    return seg[node] = histogram[left_init] < histogram[right_init] ? left_init : right_init;
}

int seg_query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) {
        return -1;
    }
    if (l <= s && e <= r) {
        return seg[node];
    }

    int mid = (s + e) / 2;
    int left_query = seg_query(node * 2, s, mid, l, r);
    int right_query = seg_query(node * 2 + 1, mid + 1, e, l, r);

    if (left_query == -1) {
        return right_query;
    }
    if (right_query == -1) {
        return left_query;
    }
    return histogram[left_query] < histogram[right_query] ? left_query : right_query;
}

ll largest_area(int l, int r) {
    int min_idx = seg_query(1, 0, N - 1, l, r);

    ll res = (ll)(r - l + 1) * (ll)histogram[min_idx];

    if (l <= min_idx - 1) {
        res = max(res, largest_area(l, min_idx - 1));
    }
    if (min_idx + 1 <= r) {
        res = max(res, largest_area(min_idx + 1, r));
    }

    return res;
}

int main() {
    fastio;

    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            cin >> histogram[i];
        }

        seg_init(1, 0, N - 1);
        ans = largest_area(0, N - 1);
        cout << ans << '\n';
    }

    return 0;
}