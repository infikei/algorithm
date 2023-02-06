#include <iostream>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int W, H;
    cin >> W >> H;

    double D = sqrt(W * W + H * H);
    cout << fixed;
    cout.precision(9);
    cout << W + H - D << '\n';

    return 0;
}