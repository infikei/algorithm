// Solve 2025-10-17

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

vector<int> tree[100001];
map<int, ll> ans;

map<int, ll> recur(int cur) {
    map<int, ll> ret;
    ret[1] = 1;
    ans[1]++;

    for (int nxt : tree[cur]) {
        map<int, ll> n_ret = recur(nxt);

        for (auto it = ret.begin(); it != ret.end(); it++) {
            for (auto it2 = n_ret.begin(); it2 != n_ret.end(); it2++) {
                // cout << "   " << it->first << ' ' <<  it2->first << ' ' << it->second << ' ' << it2->second << '\n';
                ans[it->first + it2->first] += it->second * it2->second;
            }
        }

        for (auto it = n_ret.begin(); it != n_ret.end(); it++) {
            ret[it->first + 1] += it->second;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int u = 2; u <= n; u++) {
        int par;
        cin >> par;
        tree[par].push_back(u);
    }

    recur(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
    return 0;
}
