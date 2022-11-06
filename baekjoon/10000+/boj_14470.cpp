#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int ans;
    if (A > 0) {
        ans = (B - A) * E;
    }
    else {
        ans = -A * C + D + B * E;
    }

    cout << ans << '\n';

    return 0;
}