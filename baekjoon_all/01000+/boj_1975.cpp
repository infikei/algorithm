// Solve 2025-10-06

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

int memo[1001];

int get_div_cnt(int n, int q) {
    if (q == 1) return 0;

    int ret = 0;

    while (n % q == 0) {
        n /= q;
        ret++;
    }

    return ret;
}

int solution(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }

    int sqrt_n = sqrt(n);
    int ret = 0;

    for (int i = 1; i <= sqrt_n; i++) {
        if (n % i != 0) continue;

        int j = n / i;

        ret += get_div_cnt(n, i);

        if (j != i) {
            ret += get_div_cnt(n, j);
        }
    }

    return memo[n] = ret;
}

int main() {
    FASTIO;

    memset(memo, -1, sizeof memo);
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        cout << solution(n) << '\n';
    }

    return 0;
}
