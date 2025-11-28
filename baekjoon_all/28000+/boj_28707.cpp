// Solve 2025-11-28

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

struct Cmd{
    int l, r, c;

    Cmd(int l, int r, int c) : l(l), r(r), c(c) {
    }
};

string vec_to_string(vector<int>& v) {
    string s;

    for (int i = 0; i < size(v); i++) {
        s += to_string(v[i]) + ",";
    }

    return s;
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        vec.push_back(v);
    }

    int m;
    cin >> m;
    vector<Cmd> cmds;

    while (m-- > 0) {
        int l, r, c;
        cin >> l >> r >> c;
        cmds.emplace_back(l - 1, r - 1, c);
    }

    vector<int> sorted_vec = vec;
    sort(sorted_vec.begin(), sorted_vec.end());

    auto cmp = [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
        return a.first > b.first;
    };
    priority_queue<
        pair<int, vector<int>>,
        vector<pair<int, vector<int>>>,
        decltype(cmp)
        > pq(cmp);
    unordered_map<string, int> visited;
    pq.emplace(0, vec);
    visited[vec_to_string(vec)] = 0;

    while (!pq.empty()) {
        auto [cur_cost, cur_vec] = pq.top();
        pq.pop();
        string cur_str = vec_to_string(cur_vec);

        if (visited.find(cur_str) != visited.end() && cur_cost > visited[cur_str]) {
            visited[cur_str] = cur_cost;
        }

        if (cur_vec == sorted_vec) {
            cout << cur_cost << '\n';
            return 0;
        }

        for (auto [l, r, c] : cmds) {
            swap(cur_vec[l], cur_vec[r]);
            int nxt_cost = cur_cost + c;
            string nxt_str = vec_to_string(cur_vec);

            if (visited.find(nxt_str) == visited.end() || nxt_cost < visited[nxt_str]) {
                pq.emplace(cur_cost + c, cur_vec);
                visited[nxt_str] = nxt_cost;
            }

            swap(cur_vec[l], cur_vec[r]);
        }
    }

    cout << -1 << '\n';
    return 0;
}
