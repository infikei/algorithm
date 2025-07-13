// Solve 2025-07-13

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
    vector<pii> lectures;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num, s, e;
        cin >> num >> s >> e;
        lectures.emplace_back(s, e);
    }

    sort(lectures.begin(), lectures.end());
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (pii& lecture : lectures) {
        while (!pq.empty() && pq.top() <= lecture.first) {
            pq.pop();
        }

        pq.push(lecture.second);
        ans = max(ans, (int) pq.size());
    }

    cout << ans << '\n';
    return 0;
}
