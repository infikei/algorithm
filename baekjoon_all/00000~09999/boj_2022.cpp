#include <iostream>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    double x, y, c;
    cin >> x >> y >> c;

    double k, k_min = 0, k_max = min(x, y);

    while (true) {
        k = (k_min + k_max) / 2;
        double val = c * (1 / sqrt(x * x - k * k) + 1 / sqrt(y * y - k * k));

        if (abs(val - 1) < 0.0000001) {
            break;
        }
        else if (val > 1) {
            k_max = k;
        }
        else {
            k_min = k;
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << k << '\n';

    return 0;
}