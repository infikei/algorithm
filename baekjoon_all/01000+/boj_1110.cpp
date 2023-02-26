// Solve 2022-06-02
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cur = n, ans = 0;

    while (true) {
        cur = cur % 10 * 10 + (cur / 10 + cur % 10) % 10;
        ans++;
        if (cur == n) break;
    }

    cout << ans << '\n';

    return 0;
}