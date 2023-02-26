// Solve 2022-06-02
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    if (a == b && a == c) {
        ans = (a + 10) * 1000;
    }
    else if (a == b || a == c) {
        ans = (a + 10) * 100;
    }
    else if (b == c) {
        ans = (b + 10) * 100;
    }
    else {
        ans = max(a, max(b, c)) * 100;
    }

    cout << ans << '\n';

    return 0;
}