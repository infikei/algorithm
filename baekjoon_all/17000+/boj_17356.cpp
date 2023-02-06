#include <iostream>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B;
    cin >> A >> B;

    double ans = 1 / (1 + pow(10, (double)(B - A) / 400));
    cout << fixed;
    cout.precision(9);
    cout << ans << '\n';

    return 0;
}