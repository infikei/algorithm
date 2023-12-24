// Solve 2023-12-24

#include <iostream>
using namespace std;

int main() {
    int ans = 0;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;

        ans += x;
    }

    ans /= 2;

    cout << ans << '\n';

    return 0;
}
