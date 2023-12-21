// Solve 2023-12-21

#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    if (n >= 6) {
        cout << "Love is open door\n";
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (++x == 2) x = 0;

            cout << x << '\n';
        }
    }

    return 0;
}
