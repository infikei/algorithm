// Solve 2025-10-09

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
    cin >> n;
    vector<pii> pos;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        char c;
        int p;
        cin >> c >> p;
        pos.emplace_back(p, c == 'G' ? 1 : 2);

        if (c == 'L') {
            cur++;
        }
    }

    sort(pos.begin(), pos.end());
    int mx = cur;

    for (int i = 0; i < n; i++) {
        if (pos[i].second == 1) {
            cur++;
            mx = max(mx, cur);
        }
        else {
            cur--;
        }
    }

    cout << n - mx << '\n';
    return 0;
}
