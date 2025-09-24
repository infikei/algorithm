// Solve 2025-09-23

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

int a[10000];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;

    for (int i = 1; i < n; i++) {
        int pos = i - 1;
        int new_item = a[i];

        while (pos >= 0 && new_item < a[pos]) {
            if (++cnt == k) {
                cout << a[pos] << '\n';
                return 0;
            }

            a[pos + 1] = a[pos];
            pos--;
        }

        if (pos + 1 != i) {
            if (++cnt == k) {
                cout << new_item << '\n';
                return 0;
            }

            a[pos + 1] = new_item;
        }
    }

    cout << -1 << '\n';
    return 0;
}
