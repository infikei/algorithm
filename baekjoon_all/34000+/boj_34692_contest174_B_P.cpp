// Solve 2025-11-14

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

    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<int, vector<int>, greater<int>> pq_mintop;

    for (int i = 0; i < m; i++) {
        pq_mintop.push(0);
    }

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t += pq_mintop.top();
        pq_mintop.pop();
        pq_mintop.push(t);
    }

    if (pq_mintop.top() <= k) {
        cout << "WAIT" << '\n';
    }
    else {
        cout << "GO" << '\n';
    }

    return 0;
}
