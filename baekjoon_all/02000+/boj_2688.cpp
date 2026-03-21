// Solve 2026-03-18

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

ll prefix[10];
ll memo[65];

void pre_process() {
    for (int d = 0; d < 10; d++) {
        prefix[d] = 1;
    }

    for (int i = 1; i <= 64; i++) {
        for (int d = 1; d < 10; d++) {
            prefix[d] += prefix[d - 1];
        }

        memo[i] = prefix[9];
    }
}

int main() {
    FASTIO;

    pre_process();

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        cout << memo[n] << '\n';
    }

    return 0;
}
