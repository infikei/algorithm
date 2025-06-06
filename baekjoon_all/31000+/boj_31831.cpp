// Solve 2025-06-06

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

    int n, m;
    cin >> n >> m;

    int cnt = 0;
    int stress_sum = 0;

    for (int i = 0; i < n; i++) {
        int stress;
        cin >> stress;
        stress_sum += stress;

        if (stress_sum < 0) stress_sum = 0;
        if (stress_sum >= m) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
