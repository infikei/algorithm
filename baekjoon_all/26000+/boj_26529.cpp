// Solve 2026-02-16

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

ll fibo[46];

int main() {
    FASTIO;

    fibo[0] = 1;
    fibo[1] = 1;

    for (int i = 2; i <= 45; i++) {
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        cout << fibo[n] << '\n';
    }

    return 0;
}
