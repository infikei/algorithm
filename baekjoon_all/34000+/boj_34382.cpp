// Solve 2025-11-20

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

double f[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;
    double f_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f_sum += f[i];
    }

    double f_avg = f_sum / n;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (f_avg - 10 <= f[i] && f[i] <= f_avg + 10) {
            cnt++;
        }
    }

    cout << n - cnt << '\n';
    return 0;
}
