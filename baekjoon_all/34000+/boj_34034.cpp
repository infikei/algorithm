// Solve 2025-07-25

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

    vector<pii> problems;

    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        problems.emplace_back(d, i);
    }

    sort(problems.begin(), problems.end());
    int solved_cnt = 0;
    int days = 0;

    while (true) {
        if (solved_cnt >= n || days + problems[solved_cnt].first > k) break;

        days += problems[solved_cnt].first;
        solved_cnt++;
    }

    int freeze_to_need = k - solved_cnt;

    if (freeze_to_need > m) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < solved_cnt; i++) {
        int f_days = problems[i].first - 1;

        while (f_days-- > 0) {
            cout << 0 << ' ';
        }

        cout << problems[i].second << ' ';
    }

    while (days < k) {
        cout << 0 << ' ';
        days++;
    }

    cout << '\n';
    return 0;
}
