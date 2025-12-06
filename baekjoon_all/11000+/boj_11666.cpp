// Solve 2025-12-02

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

    int n, m;
    cin >> n >> m;

    vector<pii> v;

    for (int i = 0; i < n; i++) {
        int s, a;
        cin >> s >> a;
        v.emplace_back(s, s + a);
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    for (auto [s, e] : v) {
        while (!pq.empty() && pq.top() + m < s) {
            pq.pop();
        }

        if (pq.empty() || pq.top() > s) {
            ans++;
            pq.push(e);
        }
        else {
            pq.pop();
            pq.push(e);
        }
    }

    cout << n - ans << '\n';
    return 0;
}
