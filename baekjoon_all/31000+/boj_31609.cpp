// Solve 2024-07-12

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    bool checked[10] = { false };

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        checked[d] = true;
    }

    for (int d = 0; d < 10; d++) {
        if (checked[d]) {
            cout << d << '\n';
        }
    }

    return 0;
}
