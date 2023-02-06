#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int A, B, C, X, Y, ans;

int main() {
    fastio;

    cin >> A >> B >> C >> X >> Y;

    int minXY = min(X, Y);
    ans += min(A + B, C * 2) * minXY;
    X -= minXY;
    Y -= minXY;

    if (X > 0) ans += min(A, C * 2) * X;
    else ans += min(B, C * 2) * Y;
    cout << ans << '\n';

    return 0;
}