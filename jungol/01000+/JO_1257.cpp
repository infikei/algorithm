// Solve 2026-06-10

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

int prv[100000];
bool selected[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<pii> lines;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lines.emplace_back(a, b);
    }

    sort(lines.begin(), lines.end());
    memset(prv, -1, sizeof(prv));
    vector<pii> memo;

    for (int i = 0; i < n; i++) {
        auto [a, b] = lines[i];
        int idx = lower_bound(memo.begin(), memo.end(), pii(b, i)) - memo.begin();

        if (idx == size(memo)) {
            memo.emplace_back(b, i);
        }
        else {
            memo[idx] = pii(b, i);
        }

        if (idx >= 1) {
            prv[i] = memo[idx - 1].second;
        }
    }

    int last = memo.back().second;

    while (last > -1) {
        selected[last] = true;
        last = prv[last];
    }

    cout << n - size(memo) << '\n';

    for (int i = 0; i < n; i++) {
        if (!selected[i]) {
            cout << lines[i].first << '\n';
        }
    }

    return 0;
}
