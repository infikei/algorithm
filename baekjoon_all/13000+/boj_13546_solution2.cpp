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
int prv[100001];
int nxt[100001];
int s[100001];
int e[100001];
int cnt[100001];
int cnt_bucket[330];
int ans[100001];

void add_to_range(int i, bool front) {
    int v = a[i];
    int prv_v = (s[v] > e[v] ? 0 : e[v] - s[v]);

    if (s[v] > e[v]) {
        s[v] = i;
        e[v] = i;
    }
    else if (front) {
        s[v] = i;
    }
    else {
        e[v] = i;
    }

    int cur_v = e[v] - s[v];

    cnt[prv_v]--;
    cnt[cur_v]++;
    cnt_bucket[prv_v / 330]--;
    cnt_bucket[cur_v / 330]++;
}

void remove_from_range(int i, bool front) {
    int v = a[i];
    int prv_v = e[v] - s[v];

    if (front) {
        s[v] = nxt[s[v]];
    }
    else {
        e[v] = prv[e[v]];
    }

    int cur_v = (s[v] > e[v] ? 0 : e[v] - s[v]);

    cnt[prv_v]--;
    cnt[cur_v]++;
    cnt_bucket[prv_v / 330]--;
    cnt_bucket[cur_v / 330]++;
}

int find_mx() {
    for (int i = 329; i >= 0; i--) {
        if (cnt_bucket[i] >= 1) {
            int l = i * 330;
            int r = l + 330;

            for (int j = r - 1; j >= l; j--) {
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

    memset(prv, -1, sizeof prv);
    memset(nxt, 0x3f, sizeof nxt);
    memset(s, 0x3f, sizeof s);
    memset(e, -1, sizeof e);
    // 메모리를 아끼기 위해 앞에서는 tmp 배열로 사용, 뒤에서는 ans 배열로 사용
    memset(ans, -1, sizeof ans);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (ans[a[i]] != -1) {
            int j = ans[a[i]];
            prv[i] = j;
            nxt[j] = i;
        }

        ans[a[i]] = i;
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
