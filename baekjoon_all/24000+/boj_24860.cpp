// Solve 2023-10-11

#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll k[2], l[2], h[3];

    for (int i = 0; i < 2; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < 2; i++) {
        cin >> l[i];
    }

    for (int i = 0; i < 3; i++) {
        cin >> h[i];
    }

    ll ans = (k[0] * k[1] + l[0] * l[1]) * h[0] * h[1] * h[2];

    cout << ans << '\n';

    return 0;
}
