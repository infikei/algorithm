// Solve 2025-03-29

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << ' ' << 0 << '\n';
        return 0;
    }

    queue<pii> que;
    que.emplace(n, 0);
    int ans = 0;

    while (!que.empty()) {
        int iter = que.size();
        ans++;

        while (iter-- > 0) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            if (x == 1) {
                cout << ans << ' ' << y + 1 << '\n';
                return 0;
            }

            que.emplace(x - 1, y + 1);

            if (x % 3 == 0) {
                que.emplace(x / 3, y + 3);
            }

            int sqrt_x = sqrt(x);

            if (x == sqrt_x * sqrt_x) {
                que.emplace(sqrt_x, y + 5);
            }
        }
    }

    return 0;
}
