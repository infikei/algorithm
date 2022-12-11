#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int e, f, c, ans = 0;
    cin >> e >> f >> c;
    e += f;

    while (e >= c) {
        ans += e / c;
        e = e / c + e % c;
    }

    cout << ans << '\n';

    return 0;
}