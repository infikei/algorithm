// Solve 2025-01-12
// Update 2025-09-21

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

struct Ruby{
    int x, y, value;

    Ruby(int x, int y, int value) : x(x), y(y), value(value) {
    }

    bool operator<(const Ruby& rhs) const {
        return value < rhs.value;
    }

    bool operator>(const Ruby& rhs) const {
        return rhs < *this;
    }
};

int recur(int depth, int start_idx, int value_sum, int k, vector<Ruby>& rubies, vector<int>& selected) {
    if (depth == k) {
        return value_sum;
    }

    int ret = value_sum;

    for (int i = start_idx; i < size(rubies); i++) {
        Ruby& cur_ruby = rubies[i];
        bool adjacent = false;

        for (int j = 0; j < depth; j++) {
            Ruby& prev_ruby = rubies[selected[j]];

            if (abs(cur_ruby.x - prev_ruby.x) + abs(cur_ruby.y - prev_ruby.y) <= 1) {
                adjacent = true;
                break;
            }
        }

        if (!adjacent) {
            selected[depth] = i;
            int nxt_ret = recur(depth + 1, i + 1, value_sum + cur_ruby.value, k, rubies, selected);
            ret = max(ret, nxt_ret);
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;
    int n_rubies = 5 * k - 4;
    priority_queue<Ruby, vector<Ruby>, greater<Ruby>> pq_mintop;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            int v;
            cin >> v;
            pq_mintop.emplace(x, y, v);
        }

        while (size(pq_mintop) > n_rubies) {
            pq_mintop.pop();
        }
    }

    vector<Ruby> high_value_rubies;

    while (!pq_mintop.empty()) {
        high_value_rubies.push_back(pq_mintop.top());
        pq_mintop.pop();
    }

    vector<int> selected(k);
    int ans = recur(0, 0, 0, k, high_value_rubies, selected);
    cout << ans << '\n';
    return 0;
}
