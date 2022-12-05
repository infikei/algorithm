#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    int dp = t % (w * 2);
    int x = p + dp;
    if (x > w * 2) {
        x -= w * 2;
    }
    else if (x > w) {
        x = w * 2 - x;
    }

    int dq = t % (h * 2);
    int y = q + dq;
    if (y > h * 2) {
        y -= h * 2;
    }
    else if (y > h) {
        y = h * 2 - y;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}