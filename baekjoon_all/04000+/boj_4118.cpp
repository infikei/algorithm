// Solve 2025-11-07

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

bool selected[50];

int main() {
    FASTIO;

    while (true) {
        memset(selected, false, sizeof selected);
        int n;
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                int x;
                cin >> x;
                selected[x] = true;
            }
        }

        bool flag = true;

        for (int d = 1; d <= 49; d++) {
            if (!selected[d]) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "Yes" : "No") << '\n';
    }

    return 0;
}
