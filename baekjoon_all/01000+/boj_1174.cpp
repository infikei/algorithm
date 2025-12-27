// Solve 2025-12-27

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

set<ll> st;

void recur(ll cur, int from) {
    st.insert(cur);

    for (int i = from; i >= 0; i--) {
        recur(cur * 10 + i, i - 1);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    recur(0, 9);
    vector<ll> vec;

    for (ll v : st) {
        vec.push_back(v);
    }

    cout << (n > size(vec) ? -1 : vec[n - 1]) << '\n';
    return 0;
}
