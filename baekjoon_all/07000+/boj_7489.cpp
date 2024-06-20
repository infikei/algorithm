// Solve 2024-06-19

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        int x = 1;

        for (int i = 2; i <= n; i++) {
            x *= i;

            while (x % 10 == 0) {
                x /= 10;
            }

            x %= 100000;
        }

        cout << x % 10 << '\n';
    }

    return 0;
}
