// Solve 2023-12-23

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = b - a;

    if (ans < 0) ans += 24;

    cout << ans << '\n';

    return 0;
}
