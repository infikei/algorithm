#include <iostream>
#include <cmath>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int b, c, a1, a2;

int main() {
    fastio;

    cin >> b >> c >> a1 >> a2;

    double b2 = (double)b / 2;
    double ans = b2 + sqrt(b2 * b2 + c);
    cout << fixed;
    cout.precision(9);
    cout << ans << '\n';

    return 0;
}