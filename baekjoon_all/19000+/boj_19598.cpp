// Solve 2025-07-12

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

    int n;
    vector<pii> meetings;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meetings.emplace_back(s, e);
    }

    sort(meetings.begin(), meetings.end());
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (pii& meeting : meetings) {
        while (!pq.empty() && pq.top() <= meeting.first) {
            pq.pop();
        }

        pq.push(meeting.second);
        ans = max(ans, (int) pq.size());
    }

    cout << ans << '\n';
    return 0;
}
