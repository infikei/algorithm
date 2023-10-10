// Solve 2021-12-18
// Update 2023-10-10

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += i;
    }

    cout << ans << '\n';

    return 0;
}
