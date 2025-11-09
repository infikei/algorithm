// Solve 2025-11-09

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

bool visited[10];

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        memset(visited, false, sizeof visited);
        int n;
        cin >> n;

        if (n == 0) {
            cout << "Case #" << ti << ": INSOMNIA" << '\n';
            continue;
        }

        for (int i = n;; i += n) {
            int tmp = i;

            while (tmp > 0) {
                visited[tmp % 10] = true;
                tmp /= 10;
            }

            bool flag = true;

            for (int d = 0; d < 10; d++) {
                if (!visited[d]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << "Case #" << ti << ": " << i << '\n';
                break;
            }
        }
    }

    return 0;
}
