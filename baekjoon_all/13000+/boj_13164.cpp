// Solve 2025-12-10

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

int diff[300000];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    int prv;
    cin >> prv;

    for (int i = 1; i < n; i++) {
        int cur;
        cin >> cur;
        diff[i - 1] = cur - prv;
        prv = cur;
    }

    sort(diff, diff + (n - 1));
    int mn = 0;

    for (int i = 0, i_end = n - k; i < i_end; i++) {
        mn += diff[i];
    }

    cout << mn << '\n';
    return 0;
}
