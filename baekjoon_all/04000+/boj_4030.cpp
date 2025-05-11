// Solve 2025-05-11

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

    vector<int> vec = { 4, 16, 121, 529, 4096, 17956, 139129, 609961, 4726276, 20720704, 160554241, 703893961 };
    int ti = 0;

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;

        int ans = lower_bound(vec.begin(), vec.end(), b) - upper_bound(vec.begin(), vec.end(), a);
        cout << "Case " << ++ti << ": " << ans << '\n';
    }

    return 0;
}
