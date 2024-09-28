// Solve 2024-09-21

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll ans = 0;

    for (int i = 1, ie = sqrt(n); i <= ie; i++) {
        if (n % i != 0) continue;

        ans += i;
        int ii = n / i;

        if (ii != i) {
            ans += ii;
        }
    }

    cout << ans << '\n';

    return 0;
}
