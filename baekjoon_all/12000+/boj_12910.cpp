// Solve 2025-04-14

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

int cnt_by_brand[51];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int brand;
        cin >> brand;

        cnt_by_brand[brand]++;
    }

    for (int brand = 2; brand <= 50; brand++) {
        cnt_by_brand[brand] *= cnt_by_brand[brand - 1];
    }

    int ans = 0;

    for (int brand = 1; brand <= 50; brand++) {
        ans += cnt_by_brand[brand];
    }

    cout << ans << '\n';

    return 0;
}
