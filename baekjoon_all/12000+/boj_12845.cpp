// Solve 2025-09-25

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

int main() {
    FASTIO;

    int n;
    cin >> n;
    int lv_sum = 0;
    int lv_max = 0;

    for (int i = 0; i < n; i++) {
        int lv;
        cin >> lv;
        lv_sum += lv;
        lv_max = max(lv_max, lv);
    }

    cout << lv_sum + lv_max * (n - 2) << '\n';
    return 0;
}
