#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int ans = 0;

    int x;
    while (cin >> x) {
        ans += x;
    }

    cout << ans << '\n';

    return 0;
}