// Solve 2025-12-25

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

int a[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int k = 1; k <= n / 2; k++) {
        bool flag = true;

        for (int i = 0, j = n - k; i < k; i++, j++) {
            if (a[i] != a[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "yes" << '\n';
            return 0;
        }
    }

    cout << "no" << '\n';
    return 0;
}
