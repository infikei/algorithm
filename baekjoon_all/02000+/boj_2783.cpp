#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, X, Y;
    cin >> X >> Y;
    double ans = X * 1000 / (double)Y;

    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> X >> Y;
        ans = min(ans, X * 1000 / (double)Y);
    }

    cout << fixed;
    cout.precision(2);
    cout << ans << '\n';

    return 0;
}