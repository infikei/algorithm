// Solve 2026-03-14

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

    queue<int> que;
    int mx = 0;
    int mn_idx = 0;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        if (d == 1) {
            int a;
            cin >> a;
            que.push(a);

            if (size(que) > mx) {
                mx = size(que);
                mn_idx = que.back();
            }
            else if (size(que) == mx) {
                mn_idx = min(mn_idx, que.back());
            }
        }
        else {
            que.pop();
        }
    }

    cout << mx << ' ' << mn_idx << '\n';
    return 0;
}
