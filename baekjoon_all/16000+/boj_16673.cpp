#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int C, K, P;
    cin >> C >> K >> P;

    int ans = C * (C + 1) / 2 * K;
    ans += C * (C + 1) / 2 * (2 * C + 1) / 3 * P;
    cout << ans << '\n';

    return 0;
}