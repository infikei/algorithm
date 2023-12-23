// Solve 2023-12-23

#include <iostream>
using namespace std;

int main() {
    bool ans = true;

    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;

        if (x == 9) ans = false;
    }

    cout << (ans ? 'S' : 'F') << '\n';

    return 0;
}
