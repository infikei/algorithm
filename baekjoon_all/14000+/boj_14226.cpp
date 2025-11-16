// Solve 2025-11-16

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

int memo[2000][2000];

int main() {
    FASTIO;

    int s;
    cin >> s;

    memset(memo, 0x3f, sizeof memo);
    queue<pii> que;
    que.emplace(1, 0);
    memo[1][0] = 0;
    int depth = 0;

    while (!que.empty()) {
        depth++;
        int iter = size(que);

        while (iter-- > 0) {
            auto [a, b] = que.front();
            que.pop();

            if (depth < memo[a][a]) {
                memo[a][a] = depth;
                que.emplace(a, a);

                if (a == s) {
                    cout << depth << '\n';
                    return 0;
                }
            }

            if (a + b < 2000 && depth < memo[a + b][b]) {
                memo[a + b][b] = depth;
                que.emplace(a + b, b);

                if (a + b == s) {
                    cout << depth << '\n';
                    return 0;
                }
            }

            if (a - 1 >= 1 && depth < memo[a - 1][b]) {
                memo[a - 1][b] = depth;
                que.emplace(a - 1, b);

                if (a - 1 == s) {
                    cout << depth << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}
