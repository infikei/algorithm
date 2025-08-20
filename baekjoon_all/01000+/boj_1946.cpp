// Solve 2024-03-24
// Update 2025-08-19

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

int arr[100001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            arr[a] = b;
        }

        int desc_cnt = 1;
        int desc_val = arr[1];

        for (int a = 2; a <= n; a++) {
            if (desc_val > arr[a]) {
                desc_val = arr[a];
                desc_cnt++;
            }
        }

        cout << desc_cnt << '\n';
    }

    return 0;
}
