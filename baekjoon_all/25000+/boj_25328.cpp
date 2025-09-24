// Solve 2025-09-24

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

void recur(int max_depth, int begin_idx, string& s, string& res, set<string>& substr_set) {
    if (size(res) == max_depth) {
        substr_set.insert(res);
        return;
    }

    for (int i = begin_idx; i < size(s); i++) {
        res.push_back(s[i]);
        recur(max_depth, i + 1, s, res, substr_set);
        res.pop_back();
    }
}

void set_to_map(set<string>& st, map<string, int>& mp) {
    for (auto it = st.begin(); it != st.end(); it++) {
        mp[*it]++;
    }
}

int main() {
    FASTIO;

    vector<string> words(3);

    for (string& w : words) {
        cin >> w;
    }

    int k;
    cin >> k;
    map<string, int> substr_map;

    for (string& w : words) {
        set<string> substr_set;
        string tmp;
        recur(k, 0, w, tmp, substr_set);
        set_to_map(substr_set, substr_map);
    }

    int cnt = 0;

    for (auto it = substr_map.begin(); it != substr_map.end(); it++) {
        if (it->second >= 2) {
            cout << it->first << '\n';
            cnt++;
        }
    }

    if (cnt == 0) {
        cout << -1 << '\n';
    }

    return 0;
}
