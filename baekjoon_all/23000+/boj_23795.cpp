#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int ans = 0;

    while (true) {
        int x;
        cin >> x;
        if (x == -1) {
            break;
        }

        ans += x;
    }

    cout << ans << '\n';

    return 0;
}