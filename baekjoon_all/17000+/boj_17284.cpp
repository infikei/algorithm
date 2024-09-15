// Solve 2024-09-13

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 5000;
    int x;

    while (cin >> x) {
        if (x == 1) ans -= 500;
        else if (x == 2) ans -= 800;
        else ans -= 1000;
    }

    cout << ans << '\n';

    return 0;
}
