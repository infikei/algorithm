// Solve 2021-12-18
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x > 0) {
        if (y > 0) {
            cout << 1 << '\n';
        }
        else {
            cout << 4 << '\n';
        }
    }
    else {
        if (y > 0) {
            cout << 2 << '\n';
        }
        else {
            cout << 3 << '\n';
        }
    }

    return 0;
}