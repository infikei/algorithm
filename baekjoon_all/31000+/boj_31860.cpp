// Solve 2025-09-23

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
    priority_queue<int> pq_maxtop;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        pq_maxtop.push(d);
    }

    vector<int> ans;
    int satisfaction = 0;

    while (pq_maxtop.top() > k) {
        int cur = pq_maxtop.top();
        pq_maxtop.pop();
        satisfaction = satisfaction / 2 + cur;
        ans.push_back(satisfaction);
        pq_maxtop.push(cur - m);
    }

    cout << size(ans) << '\n';

    for (int& x : ans) {
        cout << x << '\n';
    }

    return 0;
}
