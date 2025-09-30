// Solve 2025-09-29

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

    int cnt = 0;
    int max_len = 0;
    int cur_len = 0;
    int prev_x = INF;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x >= prev_x) {
            cur_len++;
        }
        else {
            cnt++;
            max_len = max(max_len, cur_len);
            cur_len = 1;
        }

        prev_x = x;
    }

    max_len = max(max_len, cur_len);
    cout << cnt << ' ' << max_len << '\n';
    return 0;
}
