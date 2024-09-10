// Solve 2024-09-07

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, seed, x1, x2;
    cin >> m >> seed >> x1 >> x2;

    bool found_ans = false;

    for (int a = 0; a < m; a++) {
        for (int c = 0; c < m; c++) {
            if ((a * seed + c) % m == x1 && (a * x1 + c) % m == x2) {
                cout << a << ' ' << c << '\n';
                found_ans = true;
                break;
            }
        }

        if (found_ans) break;
    }

    return 0;
}
