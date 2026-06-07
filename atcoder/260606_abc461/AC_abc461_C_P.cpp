// Solve 2026-06-06

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

priority_queue<pii> pq;
vector<pii> vec;
set<int> st;

int main() {
    FASTIO;

    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++) {
        int c, v;
        cin >> c >> v;
        pq.emplace(v, c);
    }

    int cnt = 0;
    ll mx = 0;

    while (cnt < m) {
        auto [v, c] = pq.top();
        pq.pop();

        if (st.find(c) == st.end()) {
            st.insert(c);
            mx += v;
            cnt++;
        }
        else {
            vec.emplace_back(v, c);
        }
    }

    for (auto [v, c] : vec) {
        pq.emplace(v, c);
    }

    while (cnt < k) {
        auto [v, c] = pq.top();
        pq.pop();

        mx += v;
        cnt++;
    }

    cout << mx << '\n';
    return 0;
}
