// Solve 2025-06-13

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n, d, b, e;
        cin >> n >> d >> b >> e;

        string ans;
        int cur = n % d;

        for (int i = 0; i < b; i++) {
            cur = cur * 7 % d;
        }

        for (int i = b; i <= e; i++) {
            cur *= 7;
            ans.push_back('0' + (cur / d));
            cur %= d;
        }

        cout << "Problem set " << ti << ": " << n << " / " << d << ", base 7 digits " << b << " through " << e << ": " << ans << '\n';
    }

    return 0;
}
