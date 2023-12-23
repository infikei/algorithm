// Solve 2023-12-23

#include <iostream>
using namespace std;

int main() {
    int w, h, n, a, b;
    cin >> w >> h >> n >> a >> b;

    int p = (w / a) * (h / b);
    int ans;

    if (p == 0) {
        ans = -1;
    }
    else {
        ans = (n - 1) / p + 1;
    }

    cout << ans << '\n';

    return 0;
}
