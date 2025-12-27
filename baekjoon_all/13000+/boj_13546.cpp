// Solve 2025-12-26

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Query{
    int i, l, r, l_bucket;

    Query(int i, int l, int r, int l_bucket) : i(i), l(l), r(r), l_bucket(l_bucket) {
    }

    bool operator<(const Query& rhs) const {
        if (l_bucket != rhs.l_bucket) return l_bucket < rhs.l_bucket;
        if (r != rhs.r) return r < rhs.r;
        return l < rhs.l;
    }
};

int a[100001];
list<int> li[100001];
int cnt[100001];
int cnt_bucket[330];
int ans[100001];

void add_to_range(int i, bool front) {
    int v = a[i];
    auto& li_v = li[v];

    int prv_v = (li_v.empty() ? 0 : li_v.back() - li_v.front());
    if (front) li[v].push_front(i);
    else li[v].push_back(i);
    int cur_v = li_v.back() - li_v.front();

    cnt[prv_v]--;
    cnt[cur_v]++;
    cnt_bucket[prv_v / 330]--;
    cnt_bucket[cur_v / 330]++;
}

void remove_from_range(int i, bool front) {
    int v = a[i];
    auto& li_v = li[v];

    int prv_v = li_v.back() - li_v.front();
    if (front) li[v].pop_front();
    else li[v].pop_back();
    int cur_v = (li_v.empty() ? 0 : li_v.back() - li_v.front());

    cnt[prv_v]--;
    cnt[cur_v]++;
    cnt_bucket[prv_v / 330]--;
    cnt_bucket[cur_v / 330]++;
}

int find_mx() {
    for (int i = 329; i >= 0; i--) {
        if (cnt_bucket[i] >= 1) {
            int s = i * 330;
            int e = s + 330;

            for (int j = e - 1; j >= s; j--) {
                if (cnt[j] >= 1) {
                    return j;
                }
            }
        }
    }

    return 0;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    int sqrt_n = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    vector<Query> queries;

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(i, l, r, l / sqrt_n);
    }

    sort(queries.begin(), queries.end());
    int left = 1;
    int right = 1;
    cnt[0] = INF;
    cnt_bucket[0] = INF;
    add_to_range(1, false);

    for (auto [q_idx, l, r, l_bucket] : queries) {
        while (l < left) {
            left--;
            add_to_range(left, true);
        }

        while (right < r) {
            right++;
            add_to_range(right, false);
        }

        while (left < l) {
            remove_from_range(left, true);
            left++;
        }

        while (r < right) {
            remove_from_range(right, false);
            right--;
        }

        ans[q_idx] = find_mx();
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
