// Solve 2025-12-04

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

int recur(int depth, vector<int>& selected, vector<vector<pii>>& v) {
    if (depth == 5) return 0;

    int ret = 0;

    for (auto [x, i] : v[depth]) {
        bool flag = true;

        for (int j : selected) {
            if (i == j) {
                flag = false;
                break;
            }
        }

        if (flag) {
            selected.push_back(i);
            int nxt = x + recur(depth + 1, selected, v);
            ret = max(ret, nxt);
            selected.pop_back();
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    priority_queue<pii> pq[5];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            pq[j].emplace(x, i);
        }
    }

    vector<vector<pii>> v(5);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 && !pq[i].empty(); j++) {
            v[i].push_back(pq[i].top());
            pq[i].pop();
        }
    }

    vector<int> selected;
    cout << recur(0, selected, v) << '\n';
    return 0;
}
