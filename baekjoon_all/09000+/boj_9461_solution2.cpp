// Solve 2022-06-03
// Update 2025-10-28

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

ll padovan[101] = {0, 1, 1, 1};

int main() {
    FASTIO;

    for (int i = 4; i <= 100; i++) {
        padovan[i] = padovan[i - 3] + padovan[i - 2];
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        cout << padovan[n] << '\n';
    }

    return 0;
}
