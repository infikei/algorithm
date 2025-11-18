// Solve 2025-11-18

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

    int n, k;
    cin >> n >> k;

    ll ans = 0;
    queue<int> que;
    unordered_set<int> visited;

    while (n-- > 0) {
        int x;
        cin >> x;
        que.push(x);
        visited.insert(x);
    }

    int level = 0;

    while (k > 0) {
        int iter = size(que);
        level++;

        while (iter-- > 0 && k > 0) {
            int x = que.front();
            que.pop();

            for (int dx = -1; dx <= 1; dx += 2) {
                int nx = x + dx;

                if (k > 0 && visited.find(nx) == visited.end()) {
                    visited.insert(nx);
                    que.push(nx);
                    ans += level;
                    k--;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
