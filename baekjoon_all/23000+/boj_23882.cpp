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

void print_a(int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;

    for (int i = n - 1; i >= 1; i--) {
        int max_pos = i;

        for (int j = 0; j <= i; j++) {
            if (a[j] > a[max_pos]) {
                max_pos = j;
            }
        }

        if (max_pos != i) {
            swap(a[max_pos], a[i]);

            if (++cnt == k) {
                print_a(n);
                return 0;
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
