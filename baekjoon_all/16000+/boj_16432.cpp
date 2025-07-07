// Solve 2025-07-06

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

int n;
int memo[1000][10];

void input() {
    memset(memo, -1, sizeof memo);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        while (m-- > 0) {
            int x;
            cin >> x;

            memo[i][x] = 0;
        }
    }
}

void pro() {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (memo[i][j] == 0) {
                for (int jj = 1; jj <= 9; jj++) {
                    if (jj != j && memo[i - 1][jj] != -1) {
                        memo[i][j] = jj;
                        break;
                    }
                }

                if (memo[i][j] == 0) {
                    memo[i][j] = -1;
                }
            }
        }
    }

    stack<int> ans;

    for (int j = 1; j <= 9; j++) {
        if (memo[n - 1][j] != -1) {
            ans.push(j);
            ans.push(memo[n - 1][j]);
            break;
        }
    }

    if (ans.empty()) {
        cout << -1 << '\n';
        return;
    }

    if (n == 1) {
        ans.pop();
    }

    for (int i = n - 2; i >= 1; i--) {
        ans.push(memo[i][ans.top()]);
    }

    while (!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
