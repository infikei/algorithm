// Solve 2022-08-13
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    int x2 = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x2 += a * b;
    }

    if (x == x2) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}