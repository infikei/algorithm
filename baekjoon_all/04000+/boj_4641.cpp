// Solve 2025-10-06

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

bool visited[101];

int main() {
    FASTIO;

    while (true) {
        memset(visited, false, sizeof visited);
        int x;
        cin >> x;

        if (x == -1) break;

        while (x != 0) {
            visited[x] = true;
            cin >> x;
        }

        int cnt = 0;

        for (int i = 1; i <= 50; i++) {
            if (visited[i] && visited[i * 2]) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
