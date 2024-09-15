// Solve 2024-09-11

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout.precision(6);

    int n;
    cin >> n;

    double x = 1;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        x *= (100 - a) * 0.01;
        cout << (1 - x) * 100 << '\n';
    }

    return 0;
}
