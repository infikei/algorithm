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

int main() {
    FASTIO;

    int l, n;
    cin >> l >> n;
    vector<string> vec;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vec.push_back(s);
    }

    int k;
    cin >> k;
    unordered_map<string, int> mp;

    for (string& s : vec) {
        for (int j = 0; j <= l - k; j++) {
            mp[s.substr(j, k)]++;
        }
    }

    int mx = 0;

    for (auto [s, v] : mp) {
        mx = max(mx, v);
    }

    cout << mx << '\n';
    return 0;
}
