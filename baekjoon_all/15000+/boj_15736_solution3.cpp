// Solve 2025-01-20
// Update 2025-06-11

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

    int n;
    cin >> n;

    int low = -1;
    int high = 45826;

    while (low + 1 < high) {
        int mid = (low + high) / 2;

        if (mid * mid <= n) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << low << '\n';
    return 0;
}
