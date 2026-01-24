// Solve 2025-11-09
// Update 2026-01-19

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

bool checked[10];

bool check() {
    for (int i = 0; i < 10; i++) {
        if (!checked[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        memset(checked, false, sizeof checked);
        int n;
        cin >> n;

        if (n == 0) {
            cout << "Case #" << ti << ": INSOMNIA" << '\n';
            continue;
        }

        int cur = n;

        while (true) {
            int tmp = cur;

            while (tmp > 0) {
                checked[tmp % 10] = true;
                tmp /= 10;
            }

            if (check()) {
                break;
            }

            cur += n;
        }

        cout << "Case #" << ti << ": " << cur << '\n';
    }

    return 0;
}
