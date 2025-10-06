// Solve 2025-10-05

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

char eggplant[1001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> eggplant[i];
    }

    int m, k;
    cin >> m >> k;
    char result = 'P';

    for (int i = 0; i < m; i++) {
        bool all_white = true;

        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;

            if (eggplant[v] == 'P') {
                all_white = false;
            }
        }

        if (all_white) {
            result = 'W';
        }
    }

    cout << result << '\n';
    return 0;
}
